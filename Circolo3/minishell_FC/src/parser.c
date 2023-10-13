/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:10 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 15:59:57 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_stat;

static char	**divide_and_expand(char **arguments, t_prompt *prompt_data)
{
	char	**sub_divided;
	int		counter;
	int		quote_flags[2];

	counter = -1;
	while (arguments && arguments[++counter])
	{
		arguments[counter] = expand_variables(arguments[counter], -1, quote_flags, prompt_data);
		arguments[counter] = expand_directory(arguments[counter], -1, quote_flags, \
			shell_retrieve_env("HOME", prompt_data->envp, 4));
		sub_divided = ft_cmdsubsplit(arguments[counter], "<|>");
		ft_matrix_replace_in(&arguments, sub_divided, counter);
		counter += ft_matrixlen(sub_divided) - 1;
		ft_free_matrix(&sub_divided);
	}
	return (arguments);
}

static void	*process_arguments(char **arguments, t_prompt *prompt_data)
{
	int	exit_flag;
	int	counter;

	exit_flag = 0;
	prompt_data->cmds = populate_commands(divide_and_expand(arguments, prompt_data), -1);
	if (!prompt_data->cmds)
		return (prompt_data);
	counter = ft_lstsize(prompt_data->cmds);
	g_stat = execute_builtin(prompt_data, prompt_data->cmds, &exit_flag, 0);
	while (counter-- > 0)
		waitpid(-1, &g_stat, 0);
	if (!exit_flag && g_stat == 13)
		g_stat = 0;
	if (g_stat > 255)
		g_stat = g_stat / 255;
	if (arguments && exit_flag)
	{
		ft_lstclear(&prompt_data->cmds, release_content);
		return (NULL);
	}
	return (prompt_data);
}

void	*check_args(char *input, t_prompt *prompt_data)
{
	char	**arg_set;
	t_mini	*cmd_data;

	if (!input)
	{
		printf("exit\n");
		return (NULL);
	}
	if (input[0] != '\0')
		add_history(input);
	arg_set = ft_cmdtrim(input, " ");
	free(input);
	if (!arg_set)
		shell_error(QUOTE, NULL, 1);
	if (!arg_set)
		return ("");
	prompt_data = process_arguments(arg_set, prompt_data);
	if (prompt_data && prompt_data->cmds)
		cmd_data = prompt_data->cmds->content;
	if (prompt_data && prompt_data->cmds && cmd_data && cmd_data->full_cmd && ft_lstsize(prompt_data->cmds) == 1)
		prompt_data->envp = shell_setenv("_", cmd_data->full_cmd[ft_matrixlen(cmd_data->full_cmd) - 1], \
			prompt_data->envp, 1);
	if (prompt_data && prompt_data->cmds)
		ft_lstclear(&prompt_data->cmds, release_content);
	return (prompt_data);
}
