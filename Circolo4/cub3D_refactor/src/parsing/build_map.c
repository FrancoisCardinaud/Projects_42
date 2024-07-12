/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/12 17:30:00 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Calculates the number of lines in the map */
static int	calculate_map_height(t_data *game_data, char **file_lines,
		int start_index)
{
	int	row;
	int	col;

	row = start_index;
	while (file_lines[row])
	{
		col = 0;
		while (file_lines[row][col] == ' ' || file_lines[row][col] == '\t'
			|| file_lines[row][col] == '\r' || file_lines[row][col] == '\v'
			|| file_lines[row][col] == '\f')
			col++;
		if (file_lines[row][col] != '1')
			break ;
		row++;
	}
	game_data->mapinfo.index_end_of_map = row;
	return (row - start_index);
}

/* Populates the map array with the content from the file */
static int	populate_map_array(t_mapinfo *map_info, char **map_array,
		int current_index)
{
	int	row;
	int	col;

	map_info->width = find_max_length(map_info, current_index);
	row = 0;
	while (row < map_info->height)
	{
		col = 0;
		map_array[row] = malloc(sizeof(char) * (map_info->width + 1));
		if (!map_array[row])
			return (display_error_message(NULL, ERR_MALLOC, FAILURE));
		while (map_info->file[current_index][col]
			&& map_info->file[current_index][col] != '\n')
		{
			map_array[row][col] = map_info->file[current_index][col];
			col++;
		}
		while (col < map_info->width)
			map_array[row][col++] = '\0';
		row++;
		current_index++;
	}
	map_array[row] = NULL;
	return (SUCCESS);
}

/* Extracts the map information from the file */
static int	extract_map_info(t_data *game_data, char **file_lines,
		int start_index)
{
	game_data->mapinfo.height = calculate_map_height(game_data, file_lines,
			start_index);
	game_data->map = malloc(sizeof(char *) * (game_data->mapinfo.height + 1));
	if (!game_data->map)
		return (display_error_message(NULL, ERR_MALLOC, FAILURE));
	if (populate_map_array(&game_data->mapinfo, game_data->map,
			start_index) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/* Converts spaces into walls in the map array */
static void	convert_spaces_to_walls(t_data *game_data)
{
	int	row;
	int	col;

	row = 0;
	while (game_data->map[row])
	{
		col = 0;
		while (game_data->map[row][col] == ' '
			|| game_data->map[row][col] == '\t'
			|| game_data->map[row][col] == '\r'
			|| game_data->map[row][col] == '\v'
			|| game_data->map[row][col] == '\f')
			col++;
		while (game_data->map[row][++col])
		{
			if (game_data->map[row][col] == ' '
				&& col != game_data->map[row][ft_strlen(game_data->map[row])
				- 1])
				game_data->map[row][col] = '1';
		}
		row++;
	}
}

/* Generates the map from the given file lines */
int	generate_map(t_data *game_data, char **file_lines, int start_index)
{
	if (extract_map_info(game_data, file_lines, start_index) == FAILURE)
		return (FAILURE);
	convert_spaces_to_walls(game_data);
	return (SUCCESS);
}
