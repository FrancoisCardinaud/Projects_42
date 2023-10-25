/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:37 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/25 17:49:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_stat;

void	*shell_error(int error_type, char *parameter, int error_code)
{
	g_stat = error_code;
	if (error_type == QUOTE)
		ft_putstr_fd("minishell: could not find a matching quote\n", 2);
	else if (error_type == NDIR)
		ft_putstr_fd("minishell: file or directory not found: ", 2);
	else if (error_type == NPERM)
		ft_putstr_fd("minishell: access denied: ", 2);
	else if (error_type == NCMD)
		ft_putstr_fd("minishell: unrecognized command: ", 2);
	else if (error_type == DUPERR)
		ft_putstr_fd("minishell: failed to duplicate file descriptor\n", 2);
	else if (error_type == FORKERR)
		ft_putstr_fd("minishell: fork/process creation failed\n", 2);
	else if (error_type == PIPERR)
		ft_putstr_fd("minishell: pipe creation error\n", 2);
	else if (error_type == PIPENDERR)
		ft_putstr_fd("minishell: unexpected syntax near token '|'\n", 2);
	else if (error_type == MEM)
		ft_putstr_fd("minishell: device out of memory\n", 2);
	else if (error_type == IS_DIR)
		ft_putstr_fd("minishell: is a directory: ", 2);
	else if (error_type == NOT_DIR)
		ft_putstr_fd("minishell: is not a directory: ", 2);
	ft_putendl_fd(parameter, 2);
	return (NULL);
}

int	convert_string_to_int(const char *string, long *number)
{
	int	sign;

	sign = 1;
	*number = 0;
	while (ft_isspace(*string))
		string++;
	if (*string == '-')
		sign = -sign;
	if (*string == '-' || *string == '+')
		string++;
	if (!ft_isdigit(*string))
		return (-1);
	while (ft_isdigit(*string))
	{
		*number = 10 * *number + (*string - '0');
		string++;
	}
	if (*string && !ft_isspace(*string))
		return (-1);
	*number *= sign;
	return (0);
}

int	handle_exit(t_list *cmd, int *exit_flag)
{
	t_mini	*node;
	long	exit_status[2];

	node = cmd->content;
	*exit_flag = !cmd->next;
	if (*exit_flag)
		ft_putstr_fd("exit\n", 2);
	if (!node->full_cmd || !node->full_cmd[1])
		return (0);
	exit_status[1] = convert_string_to_int(node->full_cmd[1], &exit_status[0]);
	if (exit_status[1] == -1)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(node->full_cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (255);
	}
	else if (node->full_cmd[2])
	{
		*exit_flag = 0;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit_status[0] %= 256 + 256 * (exit_status[0] < 0);
	return (exit_status[0]);
}

void	handle_cd_error(char **arguments[2])
{
	DIR	*directory;

	directory = NULL;
	if (arguments[0][1])
		directory = opendir(arguments[0][1]);
	if (!arguments[0][1] && arguments[1][0] && !arguments[1][0][0])
	{
		g_stat = 1;
		ft_putstr_fd("minishell: HOME not set\n", 2);
	}
	if (arguments[1][0] && !arguments[0][1])
		g_stat = chdir(arguments[1][0]) == -1;
	if (arguments[0][1] && directory && access(arguments[0][1], F_OK) != -1)
		chdir(arguments[0][1]);
	else if (arguments[0][1] && access(arguments[0][1], F_OK) == -1)
		shell_error(NDIR, arguments[0][1], 1);
	else if (arguments[0][1])
		shell_error(NOT_DIR, arguments[0][1], 1);
	if (arguments[0][1] && directory)
		closedir(directory);
}

void	release_content(void *content)
{
	t_mini	*node;

	node = content;
	ft_free_matrix(&node->full_cmd);
	free(node->full_path);
	if (node->infile != STDIN_FILENO)
		close(node->infile);
	if (node->outfile != STDOUT_FILENO)
		close(node->outfile);
	free(node);
}
