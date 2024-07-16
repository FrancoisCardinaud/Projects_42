/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:08:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Initialize the setup for the rays */
static void	setup_ray_data(int column, t_ray *raycast, t_player *player_data)
{
	initialize_ray(raycast);
	raycast->slice = 2 * column / (double)WINDOW_W - 1;
	raycast->direction_x = player_data->direction_x + player_data->plane_vec_x
		* raycast->slice;
	raycast->direction_y = player_data->direction_y + player_data->plane_vec_y
		* raycast->slice;
	raycast->map_x = (int)player_data->position_x;
	raycast->map_y = (int)player_data->position_y;
	raycast->delta_distance_x = fabs(1 / raycast->direction_x);
	raycast->delta_distance_y = fabs(1 / raycast->direction_y);
}

/* Setup the DDA algorithm */
static void	initialize_dda_algo(t_ray *raycast, t_player *player_data)
{
	if (raycast->direction_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_distance_x = (player_data->position_x - raycast->map_x)
			* raycast->delta_distance_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_distance_x = (raycast->map_x + 1.0
				- player_data->position_x) * raycast->delta_distance_x;
	}
	if (raycast->direction_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_distance_y = (player_data->position_y - raycast->map_y)
			* raycast->delta_distance_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_distance_y = (raycast->map_y + 1.0
				- player_data->position_y) * raycast->delta_distance_y;
	}
}

/* Execute the DDA algorithm to find the wall hit */
static void	execute_dda(t_info *game_info, t_ray *raycast)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_distance_x < raycast->side_distance_y)
		{
			raycast->side_distance_x += raycast->delta_distance_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_distance_y += raycast->delta_distance_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (game_info->map[raycast->map_y][raycast->map_x] == '1')
			hit = 1;
	}
}

/* Compute the height of the line to be drawn */
static void	compute_line_h(t_ray *raycast, t_info *game_info,
		t_player *player_data)
{
	if (raycast->side == 0)
		raycast->wall_distance = (raycast->side_distance_x
				- raycast->delta_distance_x);
	else
		raycast->wall_distance = (raycast->side_distance_y
				- raycast->delta_distance_y);
	raycast->line_h = (int)(game_info->window_height / raycast->wall_distance);
	raycast->cast_start = -raycast->line_h / 2 + game_info->window_height / 2;
	if (raycast->cast_start < 0)
		raycast->cast_start = 0;
	raycast->cast_end = raycast->line_h / 2 + game_info->window_height / 2;
	if (raycast->cast_end >= game_info->window_height)
		raycast->cast_end = game_info->window_height - 1;
	if (raycast->side == 0)
		raycast->wall_hor = player_data->position_y + raycast->wall_distance
			* raycast->direction_y;
	else
		raycast->wall_hor = player_data->position_x + raycast->wall_distance
			* raycast->direction_x;
	raycast->wall_hor -= floor(raycast->wall_hor);
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
		compute_line_h(&raycast, game_info, player_data);
		refresh_texture_pixels(game_info, &game_info->texinfo, &raycast,
			column);
		column++;
	}
	return (OK);
}
