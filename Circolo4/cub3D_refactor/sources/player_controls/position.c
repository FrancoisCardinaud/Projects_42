/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/01 20:08:25 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Checks if the position is not colliding with a wall */
static bool	validate_wall_collision(t_data *game_data, double pos_x, double pos_y)
{
	if (game_data->map[(int)pos_y][(int)pos_x] == '0')
		return (true);
	return (false);
}

/* Checks if the position is within the bounds of the map */
static bool	validate_map_bounds(t_data *game_data, double pos_x, double pos_y)
{
	if (pos_x < 0.25 || pos_x >= game_data->mapinfo.width - 1.25)
		return (false);
	if (pos_y < 0.25 || pos_y >= game_data->mapinfo.height - 0.25)
		return (false);
	return (true);
}

/* Validates the position based on map bounds and wall collision */
static bool	validate_position(t_data *game_data, double pos_x, double pos_y)
{
	if (validate_map_bounds(game_data, pos_x, pos_y) && validate_wall_collision(game_data, pos_x, pos_y))
		return (true);
	return (false);
}

/* Verifies if the new position is valid for movement */
int	validate_move(t_data *game_data, double next_x, double next_y)
{
	int	movement_occurred;

	movement_occurred = 0;
	if (validate_position(game_data, next_x, game_data->player.pos_y))
	{
		game_data->player.pos_x = next_x;
		movement_occurred = 1;
	}
	if (validate_position(game_data, game_data->player.pos_x, next_y))
	{
		game_data->player.pos_y = next_y;
		movement_occurred = 1;
	}
	return (movement_occurred);
}
