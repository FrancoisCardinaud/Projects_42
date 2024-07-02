/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/02 20:45:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Populates the file lines into the mapinfo structure */
static void	populate_file_lines(int line_index, int char_index, int temp_index, t_data *game_data)
{
	char	*current_line;

	current_line = get_next_line(game_data->mapinfo.fd);
	while (current_line != NULL)
	{
		game_data->mapinfo.file[line_index] = ft_calloc(ft_strlen(current_line) + 1, sizeof(char));
		if (!game_data->mapinfo.file[line_index])
		{
			display_error_message(NULL, ERR_MALLOC, 0);
			return (release_memory((void **)game_data->mapinfo.file));
		}
		while (current_line[temp_index] != '\0')
			game_data->mapinfo.file[line_index][char_index++] = current_line[temp_index++];
		game_data->mapinfo.file[line_index++][char_index] = '\0';
		char_index = 0;
		temp_index = 0;
		free(current_line);
		current_line = get_next_line(game_data->mapinfo.fd);
	}
	game_data->mapinfo.file[line_index] = NULL;
}

/* Reads and parses the file data into the game structure */
void	read_file_data(char *file_path, t_data *game_data)
{
	int		line_index;
	int		temp_index;
	size_t	char_index;

	temp_index = 0;
	line_index = 0;
	char_index = 0;
	game_data->mapinfo.line_count = count_lines_in_file(file_path);
	game_data->mapinfo.path = file_path;
	game_data->mapinfo.file = ft_calloc(game_data->mapinfo.line_count + 1, sizeof(char *));
	if (!(game_data->mapinfo.file))
	{
		display_error_message(NULL, ERR_MALLOC, 0);
		return ;
	}
	game_data->mapinfo.fd = open(file_path, O_RDONLY);
	if (game_data->mapinfo.fd < 0)
		display_error_message(file_path, strerror(errno), FAILURE);
	else
	{
		populate_file_lines(line_index, char_index, temp_index, game_data);
		close(game_data->mapinfo.fd);
	}
}
