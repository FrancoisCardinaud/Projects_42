/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 20:32:28 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Validates the elements in the map grid */
static int	validate_map_elements(t_info *game_info, char **map_grid)
{
	int	row;
	int	col;

	row = 0;
	game_info->player.dir = '0';
	while (map_grid[row] != NULL)
	{
		col = 0;
		while (map_grid[row][col])
		{
			while (game_info->map[row][col] == ' '
				|| game_info->map[row][col] == '\t'
				|| game_info->map[row][col] == '\r'
				|| game_info->map[row][col] == '\v'
				|| game_info->map[row][col] == '\f')
				col++;
			if (!(ft_strchr("10NSEW", map_grid[row][col])))
				return (display_error_message(game_info->mapinfo.path,
						INVALID_CHARACTER, NOT_OK));
			if (ft_strchr("NSEW", map_grid[row][col])
				&& game_info->player.dir != '0')
				return (display_error_message(game_info->mapinfo.path,
						INVALID_PLAYER_NB, NOT_OK));
			if (ft_strchr("NSEW", map_grid[row][col])
				&& game_info->player.dir == '0')
				game_info->player.dir = map_grid[row][col];
			col++;
		}
		row++;
	}
	return (OK);
}

/* Verifies if the player's position is valid */
static int	verify_position_validity(t_info *game_info, char **map_grid)
{
	int	row;
	int	col;

	row = (int)game_info->player.pos_y;
	col = (int)game_info->player.pos_x;
	if (ft_strlen(map_grid[row - 1]) < (size_t)col || ft_strlen(map_grid[row
			+ 1]) < (size_t)col || is_whitespace(map_grid[row][col
				- 1]) == OK || is_whitespace(map_grid[row][col + 1])
					== OK
		|| is_whitespace(map_grid[row - 1][col]) == OK
		|| is_whitespace(map_grid[row + 1][col]) == OK)
		return (NOT_OK);
	return (OK);
}

/* Validates the player's position on the map */
static int	validate_player_position(t_info *game_info, char **map_grid)
{
	int	row;
	int	col;

	if (game_info->player.dir == '0')
		return (display_error_message(game_info->mapinfo.path, INVALID_DIRECTION,
				NOT_OK));
	row = 0;
	while (map_grid[row])
	{
		col = 0;
		while (map_grid[row][col])
		{
			if (ft_strchr("NSEW", map_grid[row][col]))
			{
				game_info->player.pos_x = (double)col + 0.5;
				game_info->player.pos_y = (double)row + 0.5;
				map_grid[row][col] = '0';
			}
			col++;
		}
		row++;
	}
	if (verify_position_validity(game_info, map_grid) == NOT_OK)
		return (display_error_message(game_info->mapinfo.path, INVALID_POSITION,
				NOT_OK));
	return (OK);
}

/* Verifies that the map is at the end of the file */
static int	verify_map_termination(t_mapinfo *map_info)
{
	int	row;
	int	col;

	row = map_info->index_end_of_map;
	while (map_info->file[row])
	{
		col = 0;
		while (map_info->file[row][col])
		{
			if (map_info->file[row][col] != ' '
				&& map_info->file[row][col] != '\t'
				&& map_info->file[row][col] != '\r'
				&& map_info->file[row][col] != '\n'
				&& map_info->file[row][col] != '\v'
				&& map_info->file[row][col] != '\f')
				return (NOT_OK);
			col++;
		}
		row++;
	}
	return (OK);
}

/* Validates the overall map validity */
int	validate_map(t_info *game_info, char **map_grid)
{
	if (!game_info->map)
		return (display_error_message(game_info->mapinfo.path, MAP_NOT_FOUND,
				NOT_OK));
	if (validate_map_borders(&game_info->mapinfo, map_grid) == NOT_OK)
		return (display_error_message(game_info->mapinfo.path, INVALID_MAP_BORDERS,
				NOT_OK));
	if (game_info->mapinfo.height < 3)
		return (display_error_message(game_info->mapinfo.path,
				INVALID_MAP_SIZE, NOT_OK));
	if (validate_map_elements(game_info, map_grid) == NOT_OK)
		return (NOT_OK);
	if (validate_player_position(game_info, map_grid) == NOT_OK)
		return (NOT_OK);
	if (verify_map_termination(&game_info->mapinfo) == NOT_OK)
		return (display_error_message(game_info->mapinfo.path, INVALID_MAP_ORDER,
				NOT_OK));
	return (OK);
}
