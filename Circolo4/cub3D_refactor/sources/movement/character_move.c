/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:24 by fcardina          #+#    #+#             */
/*   Updated: 2024/04/07 04:12:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_character_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->character.pos_x + data->character.dir_x * T_SPEED;
	new_y = data->character.pos_y + data->character.dir_y * T_SPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_character_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->character.pos_x - data->character.dir_x * T_SPEED;
	new_y = data->character.pos_y - data->character.dir_y * T_SPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_character_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->character.pos_x + data->character.dir_y * T_SPEED;
	new_y = data->character.pos_y - data->character.dir_x * T_SPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_character_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->character.pos_x - data->character.dir_y * T_SPEED;
	new_y = data->character.pos_y + data->character.dir_x * T_SPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_character(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->character.move_y == 1)
		moved += move_character_forward(data);
	if (data->character.move_y == -1)
		moved += move_character_backward(data);
	if (data->character.move_x == -1)
		moved += move_character_left(data);
	if (data->character.move_x == 1)
		moved += move_character_right(data);
	if (data->character.rotate != 0)
		moved += rotate_character(data, data->character.rotate);
	return (moved);
}
