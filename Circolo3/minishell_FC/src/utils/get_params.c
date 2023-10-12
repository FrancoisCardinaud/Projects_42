/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*   Created: 2021/11/04 19:48:14 by aperez-b          #+#    #+#             */
/*   Updated: 2022/03/07 21:21:29 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

extern int	g_status;

int	determine_fd(int prev_fd, char *path, int mode_flags[2])
{
	int	fd;

	if (prev_fd > 2)
		close(prev_fd);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !mode_flags[0])
		mini_perror(NDIR, path, 127);
	else if (!mode_flags[0] && access(path, R_OK) == -1)
		mini_perror(NPERM, path, 126);
	else if (mode_flags[0] && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		mini_perror(NPERM, path, 126);
	if (mode_flags[0] && mode_flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else if (mode_flags[0] && !mode_flags[1])
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (!mode_flags[0] && prev_fd != -1)
		fd = open(path, O_RDONLY);
	else
		fd = prev_fd;
	return (fd);
}

t_mini	*set_output_file_single(t_mini *node, char **args, int *index)
{
	char	*error_msg;
	int		mode_flags[2] = {1, 0};

	error_msg = "minishell: syntax error near unexpected token `newline'";
	(*index)++;
	if (args[*index])
		node->outfile = determine_fd(node->outfile, args[*index], mode_flags);
	if (!args[*index] || node->outfile == -1)
	{
		*index = -1;
		if (node->outfile != -1)
		{
			ft_putendl_fd(error_msg, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (node);
}

t_mini	*set_output_file_double(t_mini *node, char **args, int *index)
{
	char	*error_msg;
	int		mode_flags[2] = {1, 1};

	error_msg = "minishell: syntax error near unexpected token `newline'";
	(*index)++;
	if (args[++(*index)])
		node->outfile = determine_fd(node->outfile, args[*index], mode_flags);
	if (!args[*index] || node->outfile == -1)
	{
		*index = -1;
		if (node->outfile != -1)
		{
			ft_putendl_fd(error_msg, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (node);
}

t_mini	*set_input_file_single(t_mini *node, char **args, int *index)
{
	char	*error_msg;
	int		mode_flags[2] = {0, 0};

	error_msg = "minishell: syntax error near unexpected token `newline'";
	(*index)++;
	if (args[*index])
		node->infile = determine_fd(node->infile, args[*index], mode_flags);
	if (!args[*index] || node->infile == -1)
	{
		*index = -1;
		if (node->infile != -1)
		{
			ft_putendl_fd(error_msg, 2);
			g_status = 2;
		}
		else
			g_status = 1;
	}
	return (node);
}

t_mini	*set_input_file_double(t_mini *node, char **args, int *index)
{
	char	*aux[2];
	char	*error_msg;
	char	*str[2];

	str[0] = NULL;
	str[1] = NULL;
	aux[0] = NULL;
	aux[1] = "minishell: warning: here-document delimited by end-of-file";
	error_msg = "minishell: syntax error near unexpected token `newline'";
	(*index)++;
	if (args[++(*index)])
	{
		aux[0] = args[*index];
		node->infile = get_here_doc(str, aux);
	}
	if (!args[*index] || node->infile == -1)
	{
		*index = -1;
		if (node->infile != -1)
		{
			ft_putendl_fd(error_msg, 2);
			g_status = 2;
		}
	}
	return (node);
}
