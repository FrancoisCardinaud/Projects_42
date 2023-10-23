/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:10 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/24 01:08:20 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_stat;

static char	**divide_and_expand(char **arguments, t_prompt *pdat)
{
	char	**sub_divided;
	int		counter;
	int		quote_flags[2];

	counter = -1;
	while (arguments && arguments[++counter])
	{
		arguments[counter] = expand_variables(arguments[counter], -1,
				quote_flags, pdat);
		arguments[counter] = expand_dir(arguments[counter], -1, quote_flags,
				shell_retrieve_env("HOME", pdat->envp, 4));
		sub_divided = ft_cmdsubsplit(arguments[counter], "<|>");
		ft_matrix_replace_in(&arguments, sub_divided, counter);
		counter += ft_matrixlen(sub_divided) - 1;
		ft_free_matrix(&sub_divided);
	}
	return (arguments);
}

static void	*process_arguments(char **arguments, t_prompt *pdat)
{
	int	exit_flag;
	int	counter;

	exit_flag = 0;
	pdat->cmd = populate_commands(divide_and_expand(arguments, pdat), -1);
	if (!pdat->cmd)
		return (pdat);
	counter = ft_lstsize(pdat->cmd);
	g_stat = execute_builtin(pdat, pdat->cmd, &exit_flag, 0);
	while (counter-- > 0)
		waitpid(-1, &g_stat, 0);
	if (!exit_flag && g_stat == 13)
		g_stat = 0;
	if (g_stat > 255)
		g_stat = g_stat / 255;
	if (arguments && exit_flag)
	{
		ft_lstclear(&pdat->cmd, release_content);
		return (NULL);
	}
	return (pdat);
}

void	*check_args(char *output, t_prompt *p)
{
	char	**arg_set;
	t_mini	*cdata;

	if (!output)
	{
		printf("exit\n");
		return (NULL);
	}
	if (output[0] != '\0')
		add_history(output);
	arg_set = ft_cmdtrim(output, " ");
	free(output);
	if (!arg_set)
		shell_error(QUOTE, NULL, 1);
	if (!arg_set)
		return ("");
	p = process_arguments(arg_set, p);
	if (p && p->cmd)
		cdata = p->cmd->content;
	if (p && p->cmd && cdata && cdata->full_cmd && ft_lstsize(p->cmd) == 1)
		p->envp = shell_setenv("_",
				cdata->full_cmd[ft_matrixlen(cdata->full_cmd) - 1], p->envp, 1);
	if (p && p->cmd)
		ft_lstclear(&p->cmd, release_content);
	return (p);
}
