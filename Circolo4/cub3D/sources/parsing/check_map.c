/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:18:24 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_elements(t_info *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '\r'
			|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (err_msg(data->mapinfo.path, ERR_INV_LETTER, FAIL));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (err_msg(data->mapinfo.path, ERR_NUM_PLAYER, FAIL));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_position_is_valid(t_info *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| is_a_white_space(map_tab[i][j - 1]) == SUCCESS
		|| is_a_white_space(map_tab[i][j + 1]) == SUCCESS
		|| is_a_white_space(map_tab[i - 1][j]) == SUCCESS
		|| is_a_white_space(map_tab[i + 1][j]) == SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

static int	check_player_position(t_info *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (err_msg(data->mapinfo.path, ERR_PLAYER_DIR, FAIL));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_position_is_valid(data, map_tab) == FAIL)
		return (err_msg(data->mapinfo.path, ERR_PLAYER_POS, FAIL));
	return (SUCCESS);
}

static int	check_map_is_at_the_end(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map_validity(t_info *data, char **map_tab)
{
	if (!data->map)
		return (err_msg(data->mapinfo.path, ERR_MAP_MISSING, FAIL));
	if (check_map_sides(&data->mapinfo, map_tab) == FAIL)
		return (err_msg(data->mapinfo.path, ERR_MAP_NO_WALLS, FAIL));
	if (data->mapinfo.height < 3)
		return (err_msg(data->mapinfo.path, ERR_MAP_TOO_SMALL, FAIL));
	if (check_map_elements(data, map_tab) == FAIL)
		return (FAIL);
	if (check_player_position(data, map_tab) == FAIL)
		return (FAIL);
	if (check_map_is_at_the_end(&data->mapinfo) == FAIL)
		return (err_msg(data->mapinfo.path, ERR_MAP_LAST, FAIL));
	return (SUCCESS);
}
