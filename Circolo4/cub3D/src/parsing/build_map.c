/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 20:31:12 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Calculates the number of lines in the map */
static int	calculate_map_height(t_info *game_info, char **file_lines,
		int start_index)
{
	int	i;
	int	j;

	i = start_index;
	while (file_lines[i])
	{
		j = 0;
		while (file_lines[i][j])
		{
			if (file_lines[i][j] != ' ' && file_lines[i][j] != '\t'
				&& file_lines[i][j] != '\r' && file_lines[i][j] != '\v'
				&& file_lines[i][j] != '\f')
				break ;
			j++;
		}
		if (file_lines[i][j] != '1')
			break ;
		i++;
	}
	game_info->mapinfo.index_end_of_map = i;
	return (i - start_index);
}

/* Populates the map array with the content from the file */
static int	populate_map_array(t_mapinfo *map_info, char **map_array,
		int current_index)
{
	int	i;
	int	j;

	map_info->width = find_max_length(map_info, current_index);
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		map_array[i] = malloc(sizeof(char) * (map_info->width + 1));
		if (!map_array[i])
			return (display_error_message(NULL, MALLOC_ERROR, NOT_OK));
		while (map_info->file[current_index][j]
			&& map_info->file[current_index][j] != '\n')
		{
			map_array[i][j] = map_info->file[current_index][j];
			j++;
		}
		while (j < map_info->width)
		{
			map_array[i][j] = '\0';
			j++;
		}
		i++;
		current_index++;
	}
	map_array[i] = NULL;
	return (OK);
}

/* Extracts the map information from the file */
static int	extract_map_info(t_info *game_info, char **file_lines,
		int start_index)
{
	int	height;

	height = calculate_map_height(game_info, file_lines, start_index);
	game_info->mapinfo.height = height;
	game_info->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!game_info->map)
	{
		display_error_message(NULL, MALLOC_ERROR, NOT_OK);
		return (NOT_OK);
	}
	if (populate_map_array(&game_info->mapinfo, game_info->map,
			start_index) == NOT_OK)
		return (NOT_OK);
	return (OK);
}

/* Converts spaces into walls in the map array */
static void	convert_spaces_to_walls(t_info *game_info)
{
	int	row;
	int	col;

	row = 0;
	while (game_info->map[row] != NULL)
	{
		col = 0;
		while (game_info->map[row][col] != '\0'
			&& (game_info->map[row][col] == ' '
				|| game_info->map[row][col] == '\t'
				|| game_info->map[row][col] == '\r'
				|| game_info->map[row][col] == '\v'
				|| game_info->map[row][col] == '\f'))
		{
			col++;
		}
		while (game_info->map[row][col] != '\0')
		{
			if (game_info->map[row][col] == ' '
				&& col != (int)ft_strlen(game_info->map[row]) - 1)
			{
				game_info->map[row][col] = '1';
			}
			col++;
		}
		row++;
	}
}

/* Generates the map from the given file lines */
int	generate_map(t_info *game_info, char **file_lines, int start_index)
{
	if (extract_map_info(game_info, file_lines, start_index) == NOT_OK)
		return (NOT_OK);
	convert_spaces_to_walls(game_info);
	return (OK);
}
