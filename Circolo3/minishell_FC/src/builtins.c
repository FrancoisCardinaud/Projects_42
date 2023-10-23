/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:40 by mennaji          #+#    #+#             */
/*   Updated: 2023/10/13 16:08:30 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_stat;

int	shell_cd(t_prompt *shell_data)
{
	char	**path_data[2];
	char	*temp;

	g_stat = 0;
	path_data[0] = ((t_mini *)shell_data->cmds->content)->full_cmd;
	temp = shell_retrieve_env("HOME", shell_data->envp, 4);
	if (!temp)
		temp = ft_strdup("");
	path_data[1] = ft_extend_matrix(NULL, temp);
	free(temp);
	temp = getcwd(NULL, 0);
	path_data[1] = ft_extend_matrix(path_data[1], temp);
	free(temp);
	handle_cd_error(path_data);
	if (!g_stat)
		shell_data->envp = shell_setenv("OLDPWD", path_data[1][1],
				shell_data->envp, 6);
	temp = getcwd(NULL, 0);
	if (!temp)
		temp = ft_strdup("");
	path_data[1] = ft_extend_matrix(path_data[1], temp);
	free(temp);
	shell_data->envp = shell_setenv("PWD", path_data[1][2], shell_data->envp,
			3);
	ft_free_matrix(&path_data[1]);
	return (g_stat);
}

int	execute_builtin(t_prompt *shell_data, t_list *command, int *exit_flag,
		int cmd_len)
{
	char	**args;

	while (command)
	{
		args = ((t_mini *)command->content)->full_cmd;
		cmd_len = 0;
		if (args)
			cmd_len = ft_strlen(*args);
		if (args && !ft_strncmp(*args, "exit", cmd_len) && cmd_len == 4)
			g_stat = handle_exit(command, exit_flag);
		else if (!command->next && args && !ft_strncmp(*args, "cd", cmd_len)
			&& cmd_len == 2)
			g_stat = shell_cd(shell_data);
		else if (!command->next && args && !ft_strncmp(*args, "export", cmd_len)
			&& cmd_len == 6)
			g_stat = shell_export(shell_data);
		else if (!command->next && args && !ft_strncmp(*args, "unset", cmd_len)
			&& cmd_len == 5)
			g_stat = shell_unset(shell_data);
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			exec_cmd(shell_data, command);
		}
		command = command->next;
	}
	return (g_stat);
}

int	check_builtin(t_mini *cmd_data)
{
	int	cmd_length;

	if (!cmd_data->full_cmd)
		return (0);
	if ((cmd_data->full_cmd && ft_strchr(*cmd_data->full_cmd, '/'))
		|| (cmd_data->full_path && ft_strchr(cmd_data->full_path, '/')))
		return (0);
	cmd_length = ft_strlen(*cmd_data->full_cmd);
	if (!ft_strncmp(*cmd_data->full_cmd, "pwd", cmd_length) && cmd_length == 3)
		return (1);
	if (!ft_strncmp(*cmd_data->full_cmd, "env", cmd_length) && cmd_length == 3)
		return (1);
	if (!ft_strncmp(*cmd_data->full_cmd, "cd", cmd_length) && cmd_length == 2)
		return (1);
	if (!ft_strncmp(*cmd_data->full_cmd, "export", cmd_length)
		&& cmd_length == 6)
		return (1);
	if (!ft_strncmp(*cmd_data->full_cmd, "unset", cmd_length)
		&& cmd_length == 5)
		return (1);
	if (!ft_strncmp(*cmd_data->full_cmd, "echo", cmd_length) && cmd_length == 4)
		return (1);
	if (!ft_strncmp(*cmd_data->full_cmd, "exit", cmd_length) && cmd_length == 4)
		return (1);
	return (0);
}

int	shell_pwd(void)
{
	char	*directory;

	directory = getcwd(NULL, 0);
	ft_putendl_fd(directory, 1);
	free(directory);
	return (0);
}

int	shell_echo(t_list *command)
{
	int		newline_flag;
	int		index[2];
	char	**args;
	t_mini	*cmd_node;

	index[0] = 0;
	index[1] = 0;
	newline_flag = 1;
	cmd_node = command->content;
	args = cmd_node->full_cmd;
	while (args && args[++index[0]])
	{
		if (!index[1] && !ft_strncmp(args[index[0]], "-n", 2)
			&& (ft_countchar(args[index[0]],
					'n') == (int)(ft_strlen(args[index[0]]) - 1)))
			newline_flag = 0;
		else
		{
			index[1] = 1;
			ft_putstr_fd(args[index[0]], 1);
			if (args[index[0] + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	return (write(1, "\n", newline_flag) == 2);
}
