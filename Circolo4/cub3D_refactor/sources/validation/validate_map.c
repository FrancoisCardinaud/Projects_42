/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/22 17:42:08 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Validates the elements in the map grid */
static int	validate_map_elements(t_data *game_data, char **map_grid)
{
	int	row;
	int	col;

	row = 0;
	game_data->player.dir = '0';
	while (map_grid[row] != NULL)
	{
		col = 0;
		while (map_grid[row][col])
		{
			while (game_data->map[row][col] == ' ' || game_data->map[row][col] == '\t'
			|| game_data->map[row][col] == '\r'
			|| game_data->map[row][col] == '\v' || game_data->map[row][col] == '\f')
				col++;
			if (!(ft_strchr("10NSEW", map_grid[row][col])))
				return (display_error_message(game_data->mapinfo.path, ERR_INV_LETTER, FAILURE));
			if (ft_strchr("NSEW", map_grid[row][col]) && game_data->player.dir != '0')
				return (display_error_message(game_data->mapinfo.path, ERR_NUM_PLAYER, FAILURE));
			if (ft_strchr("NSEW", map_grid[row][col]) && game_data->player.dir == '0')
				game_data->player.dir = map_grid[row][col];
			col++;
		}
		row++;
	}
	return (SUCCESS);
}

/* Verifies if the player's position is valid */
static int	verify_position_validity(t_data *game_data, char **map_grid)
{
	int	row;
	int	col;

	row = (int)game_data->player.pos_y;
	col = (int)game_data->player.pos_x;
	if (ft_strlen(map_grid[row - 1]) < (size_t)col
		|| ft_strlen(map_grid[row + 1]) < (size_t)col
		|| is_whitespace(map_grid[row][col - 1]) == SUCCESS
		|| is_whitespace(map_grid[row][col + 1]) == SUCCESS
		|| is_whitespace(map_grid[row - 1][col]) == SUCCESS
		|| is_whitespace(map_grid[row + 1][col]) == SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

/* Validates the player's position on the map */
static int	validate_player_position(t_data *game_data, char **map_grid)
{
	int	row;
	int	col;

	if (game_data->player.dir == '0')
		return (display_error_message(game_data->mapinfo.path, ERR_PLAYER_DIR, FAILURE));
	row = 0;
	while (map_grid[row])
	{
		col = 0;
		while (map_grid[row][col])
		{
			if (ft_strchr("NSEW", map_grid[row][col]))
			{
				game_data->player.pos_x = (double)col + 0.5;
				game_data->player.pos_y = (double)row + 0.5;
				map_grid[row][col] = '0';
			}
			col++;
		}
		row++;
	}
	if (verify_position_validity(game_data, map_grid) == FAILURE)
		return (display_error_message(game_data->mapinfo.path, ERR_PLAYER_POS, FAILURE));
	return (SUCCESS);
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
			if (map_info->file[row][col] != ' ' && map_info->file[row][col] != '\t'
				&& map_info->file[row][col] != '\r' && map_info->file[row][col] != '\n'
				&& map_info->file[row][col] != '\v' && map_info->file[row][col] != '\f')
				return (FAILURE);
			col++;
		}
		row++;
	}
	return (SUCCESS);
}

/* Validates the overall map validity */
int	validate_map(t_data *game_data, char **map_grid)
{
	if (!game_data->map)
		return (display_error_message(game_data->mapinfo.path, ERR_MAP_MISSING, FAILURE));
	if (validate_map_borders(&game_data->mapinfo, map_grid) == FAILURE)
		return (display_error_message(game_data->mapinfo.path, ERR_MAP_NO_WALLS, FAILURE));
	if (game_data->mapinfo.height < 3)
		return (display_error_message(game_data->mapinfo.path, ERR_MAP_TOO_SMALL, FAILURE));
	if (validate_map_elements(game_data, map_grid) == FAILURE)
		return (FAILURE);
	if (validate_player_position(game_data, map_grid) == FAILURE)
		return (FAILURE);
	if (verify_map_termination(&game_data->mapinfo) == FAILURE)
		return (display_error_message(game_data->mapinfo.path, ERR_MAP_LAST, FAILURE));
	return (SUCCESS);
}
