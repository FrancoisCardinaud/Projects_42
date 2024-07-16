/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:24 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:07:57 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Moves the player forward */
static int	move_forwards(t_info *game_info)
{
	float	x;
	float	y;
	float	speed;

	if (game_info->player.running)
		speed = RUN_SPEED;
	else
		speed = WALK_SPEED;
	x = game_info->player.position_x + game_info->player.direction_x * speed;
	y = game_info->player.position_y + game_info->player.direction_y * speed;
	return (validate_move(game_info, x, y));
}

/* Moves the player backward */
static int	move_backwards(t_info *game_info)
{
	float	x;
	float	y;
	float	speed;

	if (game_info->player.running)
		speed = RUN_SPEED;
	else
		speed = WALK_SPEED;
	x = game_info->player.position_x - game_info->player.direction_x * speed;
	y = game_info->player.position_y - game_info->player.direction_y * speed;
	return (validate_move(game_info, x, y));
}

/* Moves the player to the right */
static int	move_right(t_info *game_info)
{
	float	x;
	float	y;
	float	speed;

	if (game_info->player.running)
		speed = RUN_SPEED;
	else
		speed = WALK_SPEED;
	x = game_info->player.position_x - game_info->player.direction_y * speed;
	y = game_info->player.position_y + game_info->player.direction_x * speed;
	return (validate_move(game_info, x, y));
}

/* Moves the player to the left */
static int	move_left(t_info *game_info)
{
	float	x;
	float	y;
	float	speed;

	if (game_info->player.running)
		speed = RUN_SPEED;
	else
		speed = WALK_SPEED;
	x = game_info->player.position_x + game_info->player.direction_y * speed;
	y = game_info->player.position_y - game_info->player.direction_x * speed;
	return (validate_move(game_info, x, y));
}

/* Executes the player's movement based on input */
int	execute_player_move(t_info *game_info)
{
	int	movement_occurred;

	movement_occurred = 0;
	if (game_info->player.move_hor == -1)
		movement_occurred += move_left(game_info);
	if (game_info->player.move_hor == 1)
		movement_occurred += move_right(game_info);
	if (game_info->player.move_ver == 1)
		movement_occurred += move_forwards(game_info);
	if (game_info->player.move_ver == -1)
		movement_occurred += move_backwards(game_info);
	if (game_info->player.rotation != 0)
		movement_occurred += rotate_player_direction(game_info,
				game_info->player.rotation);
	return (movement_occurred);
}
