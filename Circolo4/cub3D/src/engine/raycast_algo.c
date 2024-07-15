/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 23:11:14 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Initialize the setup for the rays */
static void	setup_ray_data(int column, t_ray *raycast,
		t_player *player_data)
{
	initialize_ray(raycast);
	raycast->camera_x = 2 * column / (double)WINDOW_W - 1;
	raycast->direction_x = player_data->direction_x + player_data->plane_vec_x
		* raycast->camera_x;
	raycast->direction_y = player_data->direction_y + player_data->plane_vec_y
		* raycast->camera_x;
	raycast->map_x = (int)player_data->pos_x;
	raycast->map_y = (int)player_data->pos_y;
	raycast->delta_distance_x = fabs(1 / raycast->direction_x);
	raycast->delta_distance_y = fabs(1 / raycast->direction_y);
}

/* Setup the DDA algorithm */
static void	initialize_dda_algo(t_ray *raycast, t_player *player_data)
{
	if (raycast->direction_x < 0)
	{
		raycast->step_x = -1;
		raycast->sidedist_x = (player_data->pos_x - raycast->map_x)
			* raycast->delta_distance_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->sidedist_x = (raycast->map_x + 1.0 - player_data->pos_x)
			* raycast->delta_distance_x;
	}
	if (raycast->direction_y < 0)
	{
		raycast->step_y = -1;
		raycast->sidedist_y = (player_data->pos_y - raycast->map_y)
			* raycast->delta_distance_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->sidedist_y = (raycast->map_y + 1.0 - player_data->pos_y)
			* raycast->delta_distance_y;
	}
}

/* Execute the DDA algorithm to find the wall hit */
static void	execute_dda(t_info *game_info, t_ray *raycast)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->sidedist_x < raycast->sidedist_y)
		{
			raycast->sidedist_x += raycast->delta_distance_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->sidedist_y += raycast->delta_distance_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (game_info->map[raycast->map_y][raycast->map_x] == '1')
			hit = 1;
	}
}

/* Compute the height of the line to be drawn */
static void	compute_line_height(t_ray *raycast, t_info *game_info,
		t_player *player_data)
{
	if (raycast->side == 0)
		raycast->wall_dist = (raycast->sidedist_x - raycast->delta_distance_x);
	else
		raycast->wall_dist = (raycast->sidedist_y - raycast->delta_distance_y);
	raycast->line_height = (int)(game_info->window_height / raycast->wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + game_info->window_height
		/ 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + game_info->window_height / 2;
	if (raycast->draw_end >= game_info->window_height)
		raycast->draw_end = game_info->window_height - 1;
	if (raycast->side == 0)
		raycast->wall_x = player_data->pos_y + raycast->wall_dist
			* raycast->direction_y;
	else
		raycast->wall_x = player_data->pos_x + raycast->wall_dist
			* raycast->direction_x;
	raycast->wall_x -= floor(raycast->wall_x);
}

int	perform_raycast(t_player *player_data, t_info *game_info)
{
	t_ray	raycast;
	int		column;

	column = 0;
	raycast = game_info->ray;
	while (column < game_info->window_width)
	{
		setup_ray_data(column, &raycast, player_data);
		initialize_dda_algo(&raycast, player_data);
		execute_dda(game_info, &raycast);
		compute_line_height(&raycast, game_info, player_data);
		refresh_texture_pixels(game_info, &game_info->texinfo, &raycast,
			column);
		column++;
	}
	return (OK);
}
