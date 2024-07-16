/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:07:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Validates the elements in the map grid */
static int	validate_map_contents(t_info *g_i, char **map_grid)
{
	int	r;
	int	c;

	r = 0;
	g_i->player.dir = '0';
	while (map_grid[r] != NULL)
	{
		c = 0;
		while (map_grid[r][c])
		{
			while (ft_strchr("\t\r\v\f ", g_i->map[r][c]))
				c++;
			if (!(ft_strchr("NSEW01", map_grid[r][c])))
				return (disp_err_msg(g_i->mapinfo.path, INV_CHAR, NOT_OK));
			if (ft_strchr("NSEW", map_grid[r][c]))
			{
				if (g_i->player.dir != '0')
					return (disp_err_msg(g_i->mapinfo.path, INV_P_NB, NOT_OK));
				g_i->player.dir = map_grid[r][c];
			}
			c++;
		}
		r++;
	}
	return (OK);
}

/* Verifies if the player's position is valid */
static int	validate_position(t_info *g_i, char **m_g)
{
	int	r;
	int	c;

	r = (int)g_i->player.position_y;
	c = (int)g_i->player.position_x;
	if (ft_strlen(m_g[r - 1]) < (size_t)c || ft_strlen(m_g[r + 1]) < (size_t)c
		|| check_is_space(m_g[r][c - 1]) == OK || check_is_space(m_g[r][c
			+ 1]) == OK || check_is_space(m_g[r - 1][c]) == OK
		|| check_is_space(m_g[r + 1][c]) == OK)
		return (NOT_OK);
	return (OK);
}

/* Validates the player's position on the map */
static int	validate_player_position(t_info *game_info, char **map_grid)
{
	int	row;
	int	col;

	if (game_info->player.dir == '0')
		return (disp_err_msg(game_info->mapinfo.path, INV_DIRECTION, NOT_OK));
	row = 0;
	while (map_grid[row])
	{
		col = 0;
		while (map_grid[row][col])
		{
			if (ft_strchr("NSEW", map_grid[row][col]))
			{
				game_info->player.position_x = (double)col + 0.5;
				game_info->player.position_y = (double)row + 0.5;
				map_grid[row][col] = '0';
			}
			col++;
		}
		row++;
	}
	if (validate_position(game_info, map_grid) == NOT_OK)
		return (disp_err_msg(game_info->mapinfo.path, INV_POSITION, NOT_OK));
	return (OK);
}

/* Verifies that the map is at the end of the file */
static int	validate_map_termination(t_mapdata *map_info)
{
	int	row;
	int	col;

	row = map_info->map_end_ind;
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
	if (validate_vertical_borders(&game_info->mapinfo, map_grid) == NOT_OK)
		return (disp_err_msg(game_info->mapinfo.path, INV_MAP_BORDERS, NOT_OK));
	if (game_info->mapinfo.height < 3)
		return (disp_err_msg(game_info->mapinfo.path, INV_MAP_SIZE, NOT_OK));
	if (!game_info->map)
		return (disp_err_msg(game_info->mapinfo.path, MAP_NOT_FOUND, NOT_OK));
	if (validate_map_contents(game_info, map_grid) == NOT_OK)
		return (NOT_OK);
	if (validate_player_position(game_info, map_grid) == NOT_OK)
		return (NOT_OK);
	if (validate_map_termination(&game_info->mapinfo) == NOT_OK)
		return (disp_err_msg(game_info->mapinfo.path, INV_MAP_ORDER, NOT_OK));
	return (OK);
}
