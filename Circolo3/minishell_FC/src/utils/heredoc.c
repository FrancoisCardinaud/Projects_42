/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:51 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 15:59:51 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_stat;

char	*assemble_here_string(char *input_str[2], size_t length, char *delimiter, char *warning)
{
	char	*temp_str;

	while (g_stat != 130 && (!input_str[0] || ft_strncmp(input_str[0], delimiter, length) \
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

int	get_here_doc(char *input_str[2], char *auxiliary[2])
{
	int		file_descriptors[2];

	g_stat = 0;
	if (pipe(file_descriptors) == -1)
	{
		shell_error(PIPERR, NULL, 1);
		return (-1);
	}
	input_str[1] = assemble_here_string(input_str, 0, auxiliary[0], auxiliary[1]);
	write(file_descriptors[WRITE_END], input_str[1], ft_strlen(input_str[1]));
	free(input_str[1]);
	close(file_descriptors[WRITE_END]);
	if (g_stat == 130)
	{
		close(file_descriptors[READ_END]);
		return (-1);
	}
	return (file_descriptors[READ_END]);
}
