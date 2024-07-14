/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:07:31 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	count_lines_in_file(char *filepath)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		display_error_message(filepath, strerror(errno), errno);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

/* Populates the file lines into the mapinfo structure */
static void	populate_file_lines(int line_idx, int char_idx, int temp_idx,
		t_info *game_info)
{
	char	*line;

	line = get_next_line(game_info->mapinfo.fd);
	while (line != NULL)
	{
		game_info->mapinfo.file[line_idx] = calloc(ft_strlen(line) + 1,
				sizeof(char));
		if (!game_info->mapinfo.file[line_idx])
		{
			display_error_message(NULL, MALLOC, 0);
			release_memory((void **)game_info->mapinfo.file);
			return ;
		}
		while (line[temp_idx] != '\0')
		{
			game_info->mapinfo.file[line_idx][char_idx++] = line[temp_idx++];
		}
		game_info->mapinfo.file[line_idx++][char_idx] = '\0';
		char_idx = 0;
		temp_idx = 0;
		free(line);
		line = get_next_line(game_info->mapinfo.fd);
	}
	game_info->mapinfo.file[line_idx] = NULL;
}

/* Reads and parses the file game_info into the game structure */
void	read_file_data(char *filepath, t_info *game_info)
{
	int		line_idx;
	int		temp_idx;
	size_t	char_idx;

	temp_idx = 0;
	line_idx = 0;
	char_idx = 0;
	game_info->mapinfo.line_count = count_lines_in_file(filepath);
	game_info->mapinfo.path = filepath;
	game_info->mapinfo.file = calloc(game_info->mapinfo.line_count + 1,
			sizeof(char *));
	if (!(game_info->mapinfo.file))
	{
		display_error_message(NULL, MALLOC, 0);
		return ;
	}
	game_info->mapinfo.fd = open(filepath, O_RDONLY);
	if (game_info->mapinfo.fd < 0)
	{
		display_error_message(filepath, strerror(errno), NOT_OK);
	}
	else
	{
		populate_file_lines(line_idx, char_idx, temp_idx, game_info);
		close(game_info->mapinfo.fd);
	}
}
