/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:39:50 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/27 15:41:19 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Resets the image structure */
void	reset_image(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}

/* Initializes the raycasting structure */
void	initialize_ray(t_ray *raycast)
{
	raycast->camera_x = 0;
	raycast->dir_x = 0;
	raycast->dir_y = 0;
	raycast->map_x = 0;
	raycast->map_y = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->sidedist_x = 0;
	raycast->sidedist_y = 0;
	raycast->deltadist_x = 0;
	raycast->deltadist_y = 0;
	raycast->wall_dist = 0;
	raycast->wall_x = 0;
	raycast->side = 0;
	raycast->line_height = 0;
	raycast->draw_start = 0;
	raycast->draw_end = 0;
}

/* Sets up the map information structure */
static void	setup_map_info(t_mapinfo *map_info)
{
	map_info->fd = 0;
	map_info->line_count = 0;
	map_info->path = NULL;
	map_info->file = NULL;
	map_info->height = 0;
	map_info->width = 0;
	map_info->index_end_of_map = 0;
}

/* Initializes the player structure */
static void	initialize_player(t_player *player_data)
{
	player_data->dir = '\0';
	player_data->pos_x = 0.0;
	player_data->pos_y = 0.0;
	player_data->dir_x = 0.0;
	player_data->dir_y = 0.0;
	player_data->plane_x = 0.0;
	player_data->plane_y = 0.0;
	player_data->has_moved = 0;
	player_data->move_x = 0;
	player_data->move_y = 0;
	player_data->rotate = 0;
}

/* Initializes the main game data structure */
void	initialize_game_data(t_data *game_data)
{
	game_data->mlx = NULL;
	game_data->win = NULL;
	game_data->win_height = WIN_HEIGHT;
	game_data->win_width = WIN_WIDTH;
	initialize_player(&game_data->player);
	initialize_texture_info(&game_data->texinfo);
	game_data->map = NULL;
	setup_map_info(&game_data->mapinfo);
	game_data->texture_pixels = NULL;
	game_data->textures = NULL;
}
