/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_game_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:39:50 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 20:05:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Initializes the raycasting structure */
void	initialize_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

/* Sets up the map information structure */
static void	initialize_map_info(t_mapinfo *map_info)
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
	player_data->pos_z = 0.0;
	player_data->dir_x = 0.0;
	player_data->dir_y = 0.0;
	player_data->plane_vector_x = 0.0;
	player_data->plane_vector_y = 0.0;
	player_data->has_moved = 0;
	player_data->move_x = 0;
	player_data->move_y = 0;
	player_data->rotate = 0;
}

/* Initializes the main game data structure */
void	initialize_game_info(t_info *game_info)
{
	game_info->mlx = NULL;
	game_info->win = NULL;
	game_info->window_height = WINDOW_H;
	game_info->window_width = WINDOW_W;
	initialize_player(&game_info->player);
	initialize_texture_info(&game_info->texinfo);
	game_info->map = NULL;
	initialize_map_info(&game_info->mapinfo);
	game_info->texture_pixels = NULL;
	game_info->textures = NULL;
}
