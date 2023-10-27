/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:17 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/27 17:04:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int		g_stat;

static void	shell_get_process_id(t_prompt *data)
{
	pid_t	process_id;

	process_id = fork();
	if (process_id < 0)
	{
		shell_error(FORKERR, NULL, 1);
		ft_free_matrix(&data->envp);
		exit(1);
	}
	if (!process_id)
	{
		ft_free_matrix(&data->envp);
		exit(1);
	}
	waitpid(process_id, NULL, 0);
	data->pid = process_id - 1;
}

static t_prompt	setup_vars(t_prompt data, char *temp_str, char **args)
{
	char	*level_str;

	temp_str = getcwd(NULL, 0);
	data.envp = shell_setenv("PWD", temp_str, data.envp, 3);
	free(temp_str);
	temp_str = shell_retrieve_env("SHLVL", data.envp, 5);
	if (!temp_str || ft_atoi(temp_str) <= 0)
		level_str = ft_strdup("1");
	else
		level_str = ft_itoa(ft_atoi(temp_str) + 1);
	free(temp_str);
	data.envp = shell_setenv("SHLVL", level_str, data.envp, 5);
	free(level_str);
	temp_str = shell_retrieve_env("PATH", data.envp, 4);
	if (!temp_str)
		data.envp = shell_setenv("PATH",
				"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", data.envp, 4);
	free(temp_str);
	temp_str = shell_retrieve_env("_", data.envp, 1);
	if (!temp_str)
		data.envp = shell_setenv("_", args[0], data.envp, 1);
	free(temp_str);
	return (data);
}

static t_prompt	initialize_shell(char **args, char **envp)
{
	t_prompt	data;
	char		*temp_str;

	temp_str = NULL;
	data.cmd = NULL;
	data.envp = ft_dup_matrix(envp);
	g_stat = 0;
	shell_get_process_id(&data);
	data = setup_vars(data, temp_str, args);
	return (data);
}

int	main(int arg_count, char **args, char **envp)
{
	char		*temp_str;
	char		*output;
	t_prompt	data;

	rl_catch_signals = 0;
	data = initialize_shell(args, envp);
	while (args && arg_count)
	{
		signal(SIGINT, handle_interrupt_signal);
		signal(SIGQUIT, SIG_IGN);
		temp_str = shell_getprompt(data);
		if (temp_str)
			output = readline(temp_str);
		else
			output = readline("guest@minishell $ ");
		free(temp_str);
		if (!check_args(output, &data))
			break ;
	}
	exit(g_stat);
}
