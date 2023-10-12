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

#include "../../inc/minishell.h"

extern int	global_stat;

static void	shell_get_process_id(t_shell_data *shell_data)
{
	pid_t	process_id;

	process_id = fork();
	if (process_id < 0)
	{
		shell_error(FORKERR, NULL, 1);
		free_env_matrix(&shell_data->env_data);
		exit(1);
	}
	if (!process_id)
	{
		free_env_matrix(&shell_data->env_data);
		exit(1);
	}
	waitpid(process_id, NULL, 0);
	shell_data->process_id = process_id - 1;
}

static t_shell_data	setup_vars(t_shell_data shell_data, char *temp_str, char **args)
{
	char	*level_str;

	temp_str = getcwd(NULL, 0);
	shell_data.env_data = shell_setenv("PWD", temp_str, shell_data.env_data, 3);
	free(temp_str);
	temp_str = shell_getenv("SHLVL", shell_data.env_data, 5);
	if (!temp_str || ft_atoi(temp_str) <= 0)
		level_str = ft_strdup("1");
	else
		level_str = ft_itoa(ft_atoi(temp_str) + 1);
	free(temp_str);
	shell_data.env_data = shell_setenv("SHLVL", level_str, shell_data.env_data, 5);
	free(level_str);
	temp_str = shell_getenv("PATH", shell_data.env_data, 4);
	if (!temp_str)
		shell_data.env_data = shell_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", shell_data.env_data, 4);
	free(temp_str);
	temp_str = shell_getenv("_", shell_data.env_data, 1);
	if (!temp_str)
		shell_data.env_data = shell_setenv("_", args[0], shell_data.env_data, 1);
	free(temp_str);
	return (shell_data);
}

static t_shell_data	initialize_shell(char **args, char **env_data)
{
	t_shell_data	shell_data;
	char			*temp_str;

	temp_str = NULL;
	shell_data.commands = NULL;
	shell_data.env_data = ft_dup_matrix(env_data);
	global_stat = 0;
	shell_get_process_id(&shell_data);
	shell_data = setup_vars(shell_data, temp_str, args);
	return (shell_data);
}

int	main(int arg_count, char **args, char **env_data)
{
	char			*temp_str;
	char			*output;
	t_shell_data	shell_data;

	shell_data = initialize_shell(args, env_data);
	while (args && arg_count)
	{
		signal(SIGINT, handle_interrupt_signal);
		signal(SIGQUIT, SIG_IGN);
		temp_str = shell_get_prompt(shell_data);
		if (temp_str)
			output = readline(temp_str);
		else
			output = readline("guest@minishell $ ");
		free(temp_str);
		if (!validate_args(output, &shell_data))
			break ;
	}
	exit(global_stat);
}