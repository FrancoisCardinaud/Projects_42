/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 05:43:24 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Checks if the position is not colliding with a wall */
static bool	validate_wall_collision(t_info *game_info, float position_x,
		float position_y)
{
	if (game_info->map[(int)position_y][(int)position_x] == '0')
		return (true);
	return (false);
}

/* Checks if the position is within the bounds of the map */
static bool	validate_map_bounds(t_info *game_info, float position_x,
		float position_y)
{
	if (position_x < 0.25 || position_x >= game_info->mapinfo.width - 1.25)
		return (false);
	if (position_y < 0.25 || position_y >= game_info->mapinfo.height - 0.25)
		return (false);
	return (true);
}

/* Validates the position based on map bounds and wall collision */
static bool	validate_position(t_info *game_info, float position_x,
		float position_y)
{
	if (validate_map_bounds(game_info, position_x, position_y)
		&& validate_wall_collision(game_info, position_x, position_y))
		return (true);
	return (false);
}

/* Verifies if the new position is valid for movement */
int	validate_move(t_info *game_info, float next_x, float next_y)
{
	int	movement_occurred;

	movement_occurred = 0;
	if (validate_position(game_info, next_x, game_info->player.position_y))
	{
		game_info->player.position_x = next_x;
		movement_occurred = 1;
	}
	if (validate_position(game_info, game_info->player.position_x, next_y))
	{
		game_info->player.position_y = next_y;
		movement_occurred = 1;
	}
	return (movement_occurred);
}
