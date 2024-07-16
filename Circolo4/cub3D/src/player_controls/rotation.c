/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 05:43:08 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Applies rotation to the player's direction first, and then of the plane */
static int	apply_rotation(t_info *game_info, float rotation_speed)
{
	t_player	*player_data;
	float		temp_x;

	player_data = &game_info->player;
	temp_x = player_data->direction_x;
	player_data->direction_x = player_data->direction_x * cos(rotation_speed)
		- player_data->direction_y * sin(rotation_speed);
	player_data->direction_y = temp_x * sin(rotation_speed)
		+ player_data->direction_y * cos(rotation_speed);
	temp_x = player_data->plane_vec_x;
	player_data->plane_vec_x = player_data->plane_vec_x * cos(rotation_speed)
		- player_data->plane_vec_y * sin(rotation_speed);
	player_data->plane_vec_y = temp_x * sin(rotation_speed)
		+ player_data->plane_vec_y * cos(rotation_speed);
	return (1);
}

/* Rotates the player's direction based on input */
int	rotate_player_direction(t_info *game_info, float rotation_direction)
{
	int		rotation_occurred;
	float	rotation_speed;

	rotation_occurred = 0;
	rotation_speed = ROTSPEED * rotation_direction;
	rotation_occurred += apply_rotation(game_info, rotation_speed);
	return (rotation_occurred);
}
