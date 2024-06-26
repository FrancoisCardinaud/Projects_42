/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:24 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/27 18:34:39 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Moves the player forward */
static int	move_forward(t_data *game_data)
{
	double	next_x;
	double	next_y;
	double speed = game_data->player.running ? RUNSPEED : MOVESPEED;

	next_x = game_data->player.pos_x + game_data->player.dir_x * speed;
    next_y = game_data->player.pos_y + game_data->player.dir_y * speed;
	return (validate_move(game_data, next_x, next_y));
}

/* Moves the player backward */
static int	move_backward(t_data *game_data)
{
	double	next_x;
	double	next_y;
	double speed = game_data->player.running ? RUNSPEED : MOVESPEED;

	next_x = game_data->player.pos_x - game_data->player.dir_x * speed;
    next_y = game_data->player.pos_y - game_data->player.dir_y * speed;
	return (validate_move(game_data, next_x, next_y));
}

/* Strafes the player to the left */
static int	strafe_left(t_data *game_data)
{
	double	next_x;
	double	next_y;
	double speed = game_data->player.running ? RUNSPEED : MOVESPEED;

	next_x = game_data->player.pos_x + game_data->player.dir_y * speed;
    next_y = game_data->player.pos_y - game_data->player.dir_x * speed;
	return (validate_move(game_data, next_x, next_y));
}

/* Strafes the player to the right */
static int	strafe_right(t_data *game_data)
{
	double	next_x;
	double	next_y;
	double speed = game_data->player.running ? RUNSPEED : MOVESPEED;

	next_x = game_data->player.pos_x - game_data->player.dir_y * speed;
    next_y = game_data->player.pos_y + game_data->player.dir_x * speed;
	return (validate_move(game_data, next_x, next_y));
}

/* Executes the player's movement based on input */
int	execute_player_move(t_data *game_data)
{
	int	movement_occurred;

	movement_occurred = 0;
	if (game_data->player.move_y == 1)
		movement_occurred += move_forward(game_data);
	if (game_data->player.move_y == -1)
		movement_occurred += move_backward(game_data);
	if (game_data->player.move_x == -1)
		movement_occurred += strafe_left(game_data);
	if (game_data->player.move_x == 1)
		movement_occurred += strafe_right(game_data);
	if (game_data->player.rotate != 0)
		movement_occurred += rotate_player_direction(game_data, game_data->player.rotate);
	return (movement_occurred);
}
