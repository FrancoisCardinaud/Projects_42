/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*   Created: 2021/11/09 10:17:00 by mbueno-g          #+#    #+#             */
/*   Updated: 2022/03/14 17:19:55 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_status;

char	*assemble_here_string(char *input_str[2], size_t length, char *delimiter, char *warning)
{
	char	*temp_str;

	while (g_status != 130 && (!input_str[0] || ft_strncmp(input_str[0], delimiter, length) \
		|| ft_strlen(delimiter) != length))
	{
		temp_str = input_str[1];
		input_str[1] = ft_strjoin(input_str[1], input_str[0]);
		free(temp_str);
		free(input_str[0]);
		input_str[0] = readline("> ");
		if (!input_str[0])
		{
			printf("%s (expected `%s\')\n", warning, delimiter);
			break ;
		}
		temp_str = input_str[0];
		input_str[0] = ft_strjoin(input_str[0], "\n");
		free(temp_str);
		length = ft_strlen(input_str[0]) - 1;
	}
	free(input_str[0]);
	return (input_str[1]);
}

int	establish_here_doc(char *input_str[2], char *auxiliary[2])
{
	int		file_descriptors[2];

	g_status = 0;
	if (pipe(file_descriptors) == -1)
	{
		mini_perror(PIPERR, NULL, 1);
		return (-1);
	}
	input_str[1] = assemble_here_string(input_str, 0, auxiliary[0], auxiliary[1]);
	write(file_descriptors[WRITE_END], input_str[1], ft_strlen(input_str[1]));
	free(input_str[1]);
	close(file_descriptors[WRITE_END]);
	if (g_status == 130)
	{
		close(file_descriptors[READ_END]);
		return (-1);
	}
	return (file_descriptors[READ_END]);
}
