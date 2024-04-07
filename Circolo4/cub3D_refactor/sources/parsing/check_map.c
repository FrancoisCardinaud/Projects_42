/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:18:24 by alexa             #+#    #+#             */
/*   Updated: 2024/04/06 19:57:07 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_elements(t_data *data, char **map_tab)
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
				return (display_error_message(data->mapinfo.path, ERR_INV_LETTER, FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (display_error_message(data->mapinfo.path, ERR_NUM_PLAYER, FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_position_is_valid(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| check_white_space(map_tab[i][j - 1]) == SUCCESS
		|| check_white_space(map_tab[i][j + 1]) == SUCCESS
		|| check_white_space(map_tab[i - 1][j]) == SUCCESS
		|| check_white_space(map_tab[i + 1][j]) == SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static int	check_player_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (display_error_message(data->mapinfo.path, ERR_PLAYER_DIR, FAILURE));
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
	if (check_position_is_valid(data, map_tab) == FAILURE)
		return (display_error_message(data->mapinfo.path, ERR_PLAYER_POS, FAILURE));
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
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	validate_map(t_data *data, char **map_tab)
{
	if (!data->map)
		return (display_error_message(data->mapinfo.path, ERR_MAP_MISSING, FAILURE));
	if (validate_map_borders(&data->mapinfo, map_tab) == FAILURE)
		return (display_error_message(data->mapinfo.path, ERR_MAP_NO_WALLS, FAILURE));
	if (data->mapinfo.height < 3)
		return (display_error_message(data->mapinfo.path, ERR_MAP_TOO_SMALL, FAILURE));
	if (check_map_elements(data, map_tab) == FAILURE)
		return (FAILURE);
	if (check_player_position(data, map_tab) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(&data->mapinfo) == FAILURE)
		return (display_error_message(data->mapinfo.path, ERR_MAP_LAST, FAILURE));
	return (SUCCESS);
}
