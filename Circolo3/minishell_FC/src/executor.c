/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:45:54 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/23 18:59:18 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_stat;

void	child_execute(t_prompt *data, t_mini *cmd_data, int len,
		t_list *cmd_list)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!check_builtin(cmd_data) && cmd_data->full_cmd)
		execve(cmd_data->full_path, cmd_data->full_cmd, data->envp);
	else if (cmd_data->full_cmd && !ft_strncmp(*cmd_data->full_cmd, "pwd", len)
		&& len == 3)
		g_stat = shell_pwd();
	else if (check_builtin(cmd_data) && cmd_data->full_cmd
		&& !ft_strncmp(*cmd_data->full_cmd, "echo", len) && len == 4)
		g_stat = shell_echo(cmd_list);
	else if (check_builtin(cmd_data) && cmd_data->full_cmd
		&& !ft_strncmp(*cmd_data->full_cmd, "env", len) && len == 3)
	{
		ft_putmatrix_fd(data->envp, 1, 1);
		g_stat = 0;
	}
}

static void	*child_redirect(t_list *cmd_list, int pipe_fd[2])
{
	t_mini	*cmd_data;

	cmd_data = cmd_list->content;
	if (cmd_data->infile != STDIN_FILENO)
	{
		if (dup2(cmd_data->infile, STDIN_FILENO) == -1)
			return (shell_error(DUPERR, NULL, 1));
		close(cmd_data->infile);
	}
	if (cmd_data->outfile != STDOUT_FILENO)
	{
		if (dup2(cmd_data->outfile, STDOUT_FILENO) == -1)
			return (shell_error(DUPERR, NULL, 1));
		close(cmd_data->outfile);
	}
	else if (cmd_list->next && dup2(pipe_fd[WRITE_END], STDOUT_FILENO) == -1)
		return (shell_error(DUPERR, NULL, 1));
	close(pipe_fd[WRITE_END]);
	return ("");
}

void	*child_routine(t_prompt *data, t_list *cmd_list, int pipe_fd[2])
{
	t_mini	*cmd_data;
	int		len;

	cmd_data = cmd_list->content;
	len = 0;
	if (cmd_data->full_cmd)
		len = ft_strlen(*cmd_data->full_cmd);
	child_redirect(cmd_list, pipe_fd);
	close(pipe_fd[READ_END]);
	child_execute(data, cmd_data, len, cmd_list);
	ft_lstclear(&data->cmds, release_content);
	exit(g_stat);
}

void	execute_child(t_prompt *data, t_list *cmd_list, int pipe_fd[2])
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid < 0)
	{
		close(pipe_fd[READ_END]);
		close(pipe_fd[WRITE_END]);
		shell_error(FORKERR, NULL, 1);
	}
	else if (!child_pid)
		child_routine(data, cmd_list, pipe_fd);
}

void	*check_to_fork(t_prompt *data, t_list *cmd_list, int pipe_fd[2])
{
	t_mini	*cmd_data;
	DIR		*directory;

	cmd_data = cmd_list->content;
	directory = NULL;
	if (cmd_data->full_cmd)
		directory = opendir(*cmd_data->full_cmd);
	if (cmd_data->infile == -1 || cmd_data->outfile == -1)
		return (NULL);
	if ((cmd_data->full_path && access(cmd_data->full_path, X_OK) == 0)
		|| check_builtin(cmd_data))
		execute_child(data, cmd_list, pipe_fd);
	else if (!check_builtin(cmd_data) && ((cmd_data->full_path
				&& !access(cmd_data->full_path, F_OK)) || directory))
		g_stat = 126;
	else if (!check_builtin(cmd_data) && cmd_data->full_cmd)
		g_stat = 127;
	if (directory)
		closedir(directory);
	return ("");
}
