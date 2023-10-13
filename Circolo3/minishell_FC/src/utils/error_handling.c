/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:33:25 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 03:51:12 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int	g_stat;

void	*shell_error(int error_type, char *parameter, int error_code)
{
	g_stat = error_code;
	char *error_messages[] = {
		"minishell: error while looking for matching quote\n",
		"minishell: No such file or directory: ",
		// ... [Add all the other error messages here]
		"minishell: Not a directory: "
	};
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error_messages[error_type], 2);
	if (parameter)
		ft_putendl_fd(parameter, 2);
	return (NULL);
}

int	convert_string_to_int(const char *string, long *number)
{
	int		sign;

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

int	handle_exit(t_list *command, int *exit_flag)
{
	t_mini	*node;
	long	exit_status[2];

	node = command->content;
	*exit_flag = !command->next;
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
	DIR		*directory;

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
