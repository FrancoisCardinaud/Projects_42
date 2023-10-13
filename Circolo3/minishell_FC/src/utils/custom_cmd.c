/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:42 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 15:59:45 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	refresh_output(char ***output_matrix, int file_descriptor)
{
	char	**temporary_matrix;
	char	*temporary_string;
	char	*line_content;

	temporary_matrix = NULL;
	line_content = NULL;
	while (1)
	{
		line_content = get_next_line(file_descriptor);
		if (!line_content)
			break ;
		temporary_string = ft_strtrim(line_content, "\n");
		free(line_content);
		temporary_matrix = ft_extend_matrix(temporary_matrix, temporary_string);
		free(temporary_string);
	}
	ft_free_matrix(output_matrix);
	*output_matrix = temporary_matrix;
}

void	execute_custom_command(char ***output, char *full_path, char *arguments, char **environment)
{
	pid_t	process_id;
	int		file_descriptors[2];
	char	**argument_matrix;

	pipe(file_descriptors);
	process_id = fork();
	if (!process_id)
	{
		close(file_descriptors[READ_END]);
		argument_matrix = ft_split(arguments, ' ');
		dup2(file_descriptors[WRITE_END], STDOUT_FILENO);
		close(file_descriptors[WRITE_END]);
		if (!access(full_path, F_OK))
			execve(full_path, argument_matrix, environment);
		exit(1);
	}
	close(file_descriptors[WRITE_END]);
	waitpid(process_id, NULL, 0);
	refresh_output(output, file_descriptors[READ_END]);
	close(file_descriptors[READ_END]);
}
