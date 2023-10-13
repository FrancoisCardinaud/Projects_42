/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [Your Name] <[Your Email]>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 by [Your Name]              #+#    #+#             */
/*   Updated: 2023/10/12 by [Your Name]              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_stat;

static void	shell_get_process_id(t_prompt *shell_data)
{
	pid_t	process_id;

	process_id = fork();
	if (process_id < 0)
	{
		shell_error(FORKERR, NULL, 1);
		ft_free_matrix(&shell_data->envp);
		exit(1);
	}
	if (!process_id)
	{
		ft_free_matrix(&shell_data->envp);
		exit(1);
	}
	waitpid(process_id, NULL, 0);
	shell_data->pid = process_id - 1;
}

static t_prompt	setup_vars(t_prompt shell_data, char *temp_str, char **args)
{
	char	*level_str;

	temp_str = getcwd(NULL, 0);
	shell_data.envp = shell_setenv("PWD", temp_str, shell_data.envp, 3);
	free(temp_str);
	temp_str = shell_retrieve_env("SHLVL", shell_data.envp, 5);
	if (!temp_str || ft_atoi(temp_str) <= 0)
		level_str = ft_strdup("1");
	else
		level_str = ft_itoa(ft_atoi(temp_str) + 1);
	free(temp_str);
	shell_data.envp = shell_setenv("SHLVL", level_str, shell_data.envp, 5);
	free(level_str);
	temp_str = shell_retrieve_env("PATH", shell_data.envp, 4);
	if (!temp_str)
		shell_data.envp = shell_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", shell_data.envp, 4);
	free(temp_str);
	temp_str = shell_retrieve_env("_", shell_data.envp, 1);
	if (!temp_str)
		shell_data.envp = shell_setenv("_", args[0], shell_data.envp, 1);
	free(temp_str);
	return (shell_data);
}

static t_prompt	initialize_shell(char **args, char **envp)
{
	t_prompt	shell_data;
	char			*temp_str;

	temp_str = NULL;
	shell_data.cmds = NULL;
	shell_data.envp = ft_dup_matrix(envp);
	g_stat = 0;
	shell_get_process_id(&shell_data);
	shell_data = setup_vars(shell_data, temp_str, args);
	return (shell_data);
}

int	main(int arg_count, char **args, char **envp)
{
	char			*temp_str;
	char			*output;
	t_prompt	shell_data;

	shell_data = initialize_shell(args, envp);
	while (args && arg_count)
	{
		signal(SIGINT, handle_interrupt_signal);
		signal(SIGQUIT, SIG_IGN);
		temp_str = shell_getprompt(shell_data);
		if (temp_str)
			output = readline(temp_str);
		else
			output = readline("guest@minishell $ ");
		free(temp_str);
		if (!check_args(output, &shell_data))
			break ;
	}
	exit(g_stat);
}