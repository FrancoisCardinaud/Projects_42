/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/12 17:29:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Applies rotation to the player's direction first, and then of the plane */
static int	apply_rotation(t_data *game_data, float rotation_speed)
{
	t_player	*player_data;
	float		temp_x;

	player_data = &game_data->player;
	temp_x = player_data->dir_x;
	player_data->dir_x = player_data->dir_x * cos(rotation_speed)
		- player_data->dir_y * sin(rotation_speed);
	player_data->dir_y = temp_x * sin(rotation_speed) + player_data->dir_y
		* cos(rotation_speed);
	temp_x = player_data->plane_vector_x;
	player_data->plane_vector_x = player_data->plane_vector_x
		* cos(rotation_speed) - player_data->plane_vector_y
		* sin(rotation_speed);
	player_data->plane_vector_y = temp_x * sin(rotation_speed)
		+ player_data->plane_vector_y * cos(rotation_speed);
	return (1);
}

/* Rotates the player's direction based on input */
int	rotate_player_direction(t_data *game_data, float rotation_direction)
{
	int		rotation_occurred;
	float	rotation_speed;

	rotation_occurred = 0;
	rotation_speed = ROTSPEED * rotation_direction;
	rotation_occurred += apply_rotation(game_data, rotation_speed);
	return (rotation_occurred);
}
