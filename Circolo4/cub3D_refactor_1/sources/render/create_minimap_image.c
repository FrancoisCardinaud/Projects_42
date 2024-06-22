/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:26:51 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/22 15:39:40 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Draws pixels for a minimap tile */
static void	draw_minimap_tile_pixels(t_minimap *mini_map, int tile_x, int tile_y, int tile_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < mini_map->tile_size)
	{
		j = 0;
		while (j < mini_map->tile_size)
		{
			put_pixel_in_image(mini_map->img, tile_x + j, i + tile_y, tile_color);
			j++;
		}
		i++;
	}
}

/* Renders a minimap tile */
static void	render_minimap_tile(t_minimap *mini_map, int tile_x, int tile_y)
{
	if (mini_map->map[tile_y][tile_x] == 'P')
		draw_minimap_tile_pixels(mini_map, tile_x * mini_map->tile_size,
			tile_y * mini_map->tile_size, MMAP_COLOR_PLAYER);
	else if (mini_map->map[tile_y][tile_x] == '1')
		draw_minimap_tile_pixels(mini_map, tile_x * mini_map->tile_size,
			tile_y * mini_map->tile_size, MMAP_COLOR_WALL);
	else if (mini_map->map[tile_y][tile_x] == '0')
		draw_minimap_tile_pixels(mini_map, tile_x * mini_map->tile_size,
			tile_y * mini_map->tile_size, MMAP_COLOR_FLOOR);
	else if (mini_map->map[tile_y][tile_x] == ' ')
		draw_minimap_tile_pixels(mini_map, tile_x * mini_map->tile_size,
			tile_y * mini_map->tile_size, MMAP_COLOR_SPACE);
}

/* Draws the border pixels for the minimap image */
static void	draw_minimap_border_pixels(t_minimap *mini_map, int border_color)
{
	int	map_size;
	int	tile_x;
	int	tile_y;

	map_size = MMAP_PIXEL_SIZE + mini_map->tile_size;
	tile_y = 0;
	while (tile_y < map_size)
	{
		tile_x = 0;
		while (tile_x <= map_size)
		{
			if (tile_x < 5 || tile_x > map_size - 5 || tile_y < 5 || tile_y > map_size - 5)
				put_pixel_in_image(mini_map->img, tile_x, tile_y, border_color);
			tile_x++;
		}
		tile_y++;
	}
}

/* Renders the minimap */
static void	render_minimap(t_minimap *mini_map)
{
	int	tile_x;
	int	tile_y;

	tile_y = 0;
	while (tile_y < mini_map->size)
	{
		tile_x = 0;
		while (tile_x < mini_map->size)
		{
			if (!mini_map->map[tile_y] || !mini_map->map[tile_y][tile_x]
				|| mini_map->map[tile_y][tile_x] == '\0')
				break ;
			render_minimap_tile(mini_map, tile_x, tile_y);
			tile_x++;
		}
		tile_y++;
	}
	draw_minimap_border_pixels(mini_map, MMAP_COLOR_SPACE);
}

/* Displays the minimap image */
void	display_minimap(t_data *game_data, t_minimap *mini_map)
{
	int	image_size;

	image_size = MMAP_PIXEL_SIZE + mini_map->tile_size;
	setup_image(game_data, &game_data->minimap, image_size, image_size);
	render_minimap(mini_map);
	mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->minimap.img,
		mini_map->tile_size, game_data->win_height
		- (MMAP_PIXEL_SIZE + (mini_map->tile_size * 2)));
	mlx_destroy_image(game_data->mlx, game_data->minimap.img);
}
