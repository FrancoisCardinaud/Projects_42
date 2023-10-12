/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*   By: [Your Name] <[Your Email]>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 by [Your Name]              #+#    #+#             */
/*   Updated: 2023/10/12 by [Your Name]              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int	global_stat;

void	child_execute(t_prompt *shell_data, t_mini *cmd_data, int len, t_list *cmd_list)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!is_command_builtin(cmd_data) && cmd_data->full_cmd)
		execve(cmd_data->full_path, cmd_data->full_cmd, shell_data->envp);
	else if (cmd_data->full_cmd && !ft_strncmp(*cmd_data->full_cmd, "pwd", len) \
		&& len == 3)
		global_stat = shell_pwd();
	else if (is_command_builtin(cmd_data) && cmd_data->full_cmd && \
		!ft_strncmp(*cmd_data->full_cmd, "echo", len) && len == 4)
		global_stat = shell_echo(cmd_list);
	else if (is_command_builtin(cmd_data) && cmd_data->full_cmd && \
		!ft_strncmp(*cmd_data->full_cmd, "env", len) && len == 3)
	{
		print_env_matrix(shell_data->envp, 1, 1);
		global_stat = 0;
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

void	*child_routine(t_prompt *shell_data, t_list *cmd_list, int pipe_fd[2])
{
	t_mini	*cmd_data;
	int		len;

	cmd_data = cmd_list->content;
	len = 0;
	if (cmd_data->full_cmd)
		len = ft_strlen(*cmd_data->full_cmd);
	child_redirect(cmd_list, pipe_fd);
	close(pipe_fd[READ_END]);
	child_execute(shell_data, cmd_data, len, cmd_list);
	clear_command_list(&shell_data->cmds, free_content);
	exit(global_stat);
}

void	execute_child(t_prompt *shell_data, t_list *cmd_list, int pipe_fd[2])
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
		child_routine(shell_data, cmd_list, pipe_fd);
}

void	*check_to_fork(t_prompt *shell_data, t_list *cmd_list, int pipe_fd[2])
{
	t_mini	*cmd_data;
	DIR		*directory;

	cmd_data = cmd_list->content;
	directory = NULL;
	if (cmd_data->full_cmd)
		directory = opendir(*cmd_data->full_cmd);
	if (cmd_data->infile == -1 || cmd_data->outfile == -1)
		return (NULL);
	if ((cmd_data->full_path && access(cmd_data->full_path, X_OK) == 0) || is_command_builtin(cmd_data))
		execute_child(shell_data, cmd_list, pipe_fd);
	else if (!is_command_builtin(cmd_data) && ((cmd_data->full_path && \
		!access(cmd_data->full_path, F_OK)) || directory))
		global_stat = 126;
	else if (!is_command_builtin(cmd_data) && cmd_data->full_cmd)
		global_stat = 127;
	if (directory)
		closedir(directory);
	return ("");
}
