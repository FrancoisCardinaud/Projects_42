/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/23 17:50:43 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Initialize the setup for the rays */
static void	initialize_ray_info(int column, t_ray *raycast, t_player *player_data)
{
	initialize_ray(raycast);
	raycast->camera_x = 2 * column / (double)WIN_WIDTH - 1;
	raycast->dir_x = player_data->dir_x + player_data->plane_x * raycast->camera_x;
	raycast->dir_y = player_data->dir_y + player_data->plane_y * raycast->camera_x;
	raycast->map_x = (int)player_data->pos_x;
	raycast->map_y = (int)player_data->pos_y;
	raycast->deltadist_x = fabs(1 / raycast->dir_x);
	raycast->deltadist_y = fabs(1 / raycast->dir_y);
}

/* Setup the DDA algorithm */
static void	setup_dda(t_ray *raycast, t_player *player_data)
{
	if (raycast->dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->sidedist_x = (player_data->pos_x - raycast->map_x) * raycast->deltadist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->sidedist_x = (raycast->map_x + 1.0 - player_data->pos_x) * raycast->deltadist_x;
	}
	if (raycast->dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->sidedist_y = (player_data->pos_y - raycast->map_y) * raycast->deltadist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->sidedist_y = (raycast->map_y + 1.0 - player_data->pos_y) * raycast->deltadist_y;
	}
}

/* Execute the DDA algorithm to find the wall hit */
static void	execute_dda(t_data *game_data, t_ray *raycast)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->sidedist_x < raycast->sidedist_y)
		{
			raycast->sidedist_x += raycast->deltadist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->sidedist_y += raycast->deltadist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (raycast->map_y < 0.25
			|| raycast->map_x < 0.25
			|| raycast->map_y > game_data->mapinfo.height - 0.25
			|| raycast->map_x > game_data->mapinfo.width - 1.25)
			break ;
		else if (game_data->map[raycast->map_y][raycast->map_x] > '0')
			hit = 1;
	}
}

/* Compute the height of the line to be drawn */
static void	compute_line_height(t_ray *raycast, t_data *game_data, t_player *player_data)
{
	if (raycast->side == 0)
		raycast->wall_dist = (raycast->sidedist_x - raycast->deltadist_x);
	else
		raycast->wall_dist = (raycast->sidedist_y - raycast->deltadist_y);
	raycast->line_height = (int)(game_data->win_height / raycast->wall_dist);
	raycast->draw_start = -(raycast->line_height) / 2 + game_data->win_height / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + game_data->win_height / 2;
	if (raycast->draw_end >= game_data->win_height)
		raycast->draw_end = game_data->win_height - 1;
	if (raycast->side == 0)
		raycast->wall_x = player_data->pos_y + raycast->wall_dist * raycast->dir_y;
	else
		raycast->wall_x = player_data->pos_x + raycast->wall_dist * raycast->dir_x;
	raycast->wall_x -= floor(raycast->wall_x);
}

int	perform_raycast(t_player *player_data, t_data *game_data)
{
	t_ray	raycast;
	int		column;

	column = 0;
	raycast = game_data->ray;
	while (column < game_data->win_width)
	{
		initialize_ray_info(column, &raycast, player_data);
		setup_dda(&raycast, player_data);
		execute_dda(game_data, &raycast);
		compute_line_height(&raycast, game_data, player_data);
		refresh_texture_pixels(game_data, &game_data->texinfo, &raycast, column);
		column++;
	}
	return (SUCCESS);
}
