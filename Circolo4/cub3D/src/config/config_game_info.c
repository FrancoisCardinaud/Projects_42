/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_game_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:39:50 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 05:39:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Initializes the raycasting structure */
void	initialize_ray(t_ray *ray)
{
	ray->pov = 0;
	ray->direction_x = 0;
	ray->direction_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_distance_x = 0;
	ray->side_distance_y = 0;
	ray->delta_distance_x = 0;
	ray->delta_distance_y = 0;
	ray->wall_distance = 0;
	ray->wall_hor = 0;
	ray->side = 0;
	ray->line_h = 0;
	ray->cast_start = 0;
	ray->cast_end = 0;
}

/* Sets up the map information structure */
static void	initialize_map_info(t_mapdata *map_info)
{
	map_info->fd = 0;
	map_info->line_nb = 0;
	map_info->path = NULL;
	map_info->file = NULL;
	map_info->height = 0;
	map_info->width = 0;
	map_info->end_of_map_index = 0;
}

/* Initializes the player structure */
static void	initialize_player(t_player *player_data)
{
	player_data->dir = '\0';
	player_data->position_x = 0.0;
	player_data->position_y = 0.0;
	player_data->position_z = 0.0;
	player_data->direction_x = 0.0;
	player_data->direction_y = 0.0;
	player_data->plane_vec_x = 0.0;
	player_data->plane_vec_y = 0.0;
	player_data->has_moved = 0;
	player_data->move_hor = 0;
	player_data->move_ver = 0;
	player_data->rotation = 0;
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
	game_info->tex_pixels = NULL;
	game_info->textures = NULL;
}
