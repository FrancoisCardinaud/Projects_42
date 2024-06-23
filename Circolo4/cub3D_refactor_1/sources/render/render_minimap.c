/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:29:15 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/23 16:55:20 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Calculate the offset for the minimap */
static int	calculate_minimap_offset(t_minimap *mini_map, int map_size, int player_pos)
{
	if (player_pos > mini_map->view_dist && map_size - player_pos > mini_map->view_dist + 1)
		return (player_pos - mini_map->view_dist);
	if (player_pos > mini_map->view_dist && map_size - player_pos <= mini_map->view_dist + 1)
		return (map_size - mini_map->size);
	return (0);
}

/* Validate if a map coordinate is within bounds */
static bool	validate_map_coordinate(int coord, int size)
{
	if (coord < size)
		return (true);
	return (false);
}

/* Create a line for the minimap */
static char	*create_minimap_line(t_data *game_data, t_minimap *mini_map, int coord_y)
{
	char	*map_line;
	int		coord_x;

	map_line = ft_calloc(mini_map->size + 1, sizeof * map_line);
	if (!map_line)
		return (NULL);
	coord_x = 0;
	while (coord_x < mini_map->size && coord_x < game_data->mapinfo.width)
	{
		if (!validate_map_coordinate(coord_y + mini_map->offset_y, game_data->mapinfo.height)
			|| !validate_map_coordinate(coord_x + mini_map->offset_x, game_data->mapinfo.width))
			map_line[coord_x] = '\0';
		else if ((int)game_data->player.pos_x == (coord_x + mini_map->offset_x)
			&& (int)game_data->player.pos_y == (coord_y + mini_map->offset_y))
			map_line[coord_x] = 'P';
		else if (game_data->map[coord_y + mini_map->offset_y][coord_x + mini_map->offset_x] == '1')
			map_line[coord_x] = '1';
		else if (game_data->map[coord_y + mini_map->offset_y][coord_x + mini_map->offset_x] == '0')
			map_line[coord_x] = '0';
		else
			map_line[coord_x] = '\0';
		coord_x++;
	}
	return (map_line);
}

/* Construct the minimap */
static char	**construct_minimap(t_data *game_data, t_minimap *mini_map)
{
	char	**mini_map_array;
	int		coord_y;

	mini_map_array = ft_calloc(mini_map->size + 1, sizeof * mini_map_array);
	if (!mini_map_array)
		return (NULL);
	coord_y = 0;
	while (coord_y < mini_map->size && coord_y < game_data->mapinfo.height)
	{
		mini_map_array[coord_y] = create_minimap_line(game_data, mini_map, coord_y);
		if (!mini_map_array[coord_y])
		{
			release_memory((void **)mini_map_array);
			return (NULL);
		}
		coord_y++;
	}
	return (mini_map_array);
}

/* Draw the minimap */
void	draw_minimap(t_data *game_data)
{
	t_minimap	mini_map;

	mini_map.map = NULL;
	mini_map.img = &game_data->minimap;
	mini_map.view_dist = MMAP_VIEW_DIST;
	mini_map.size = (2 * mini_map.view_dist) + 1;
	mini_map.tile_size = MMAP_PIXEL_SIZE / (2 * mini_map.view_dist);
	mini_map.offset_x = calculate_minimap_offset(&mini_map,
			game_data->mapinfo.width, (int)game_data->player.pos_x);
	mini_map.offset_y = calculate_minimap_offset(&mini_map,
			game_data->mapinfo.height, (int)game_data->player.pos_y);
	mini_map.map = construct_minimap(game_data, &mini_map);
	if (!mini_map.map)
	{
		display_error_message(NULL, ERR_MALLOC, 0);
		return ;
	}
	if (MMAP_DEBUG_MSG)
		show_minimap_debug(&mini_map);
	display_minimap(game_data, &mini_map);
	release_memory((void **)mini_map.map);
}
