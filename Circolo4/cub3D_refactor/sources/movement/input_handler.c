/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/04/17 03:21:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_program(data);
	if (key == XK_Left)
		data->character.rotate -= 1;
	if (key == XK_Right)
		data->character.rotate += 1;
	if (key == XK_w)
		data->character.move_y = 1;
	if (key == XK_a)
		data->character.move_x = -1;
	if (key == XK_s)
		data->character.move_y = -1;
	if (key == XK_d)
		data->character.move_x = 1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_program(data);
	if (key == XK_w && data->character.move_y == 1)
		data->character.move_y = 0;
	if (key == XK_s && data->character.move_y == -1)
		data->character.move_y = 0;
	if (key == XK_a && data->character.move_x == -1)
		data->character.move_x += 1;
	if (key == XK_d && data->character.move_x == 1)
		data->character.move_x -= 1;
	if (key == XK_Left && data->character.rotate <= 1)
		data->character.rotate = 0;
	if (key == XK_Right && data->character.rotate >= -1)
		data->character.rotate = 0;
	return (0);
}

static void	wrap_mouse_position(t_data *data, int x, int y)
{
	if (x > data->win_width - MOUSE_WRAP_DISTANCE)
	{
		x = MOUSE_WRAP_DISTANCE;
		mlx_mouse_move(data->mlx, data->win, x, y);
	}
	if (x < MOUSE_WRAP_DISTANCE)
	{
		x = data->win_width - MOUSE_WRAP_DISTANCE;
		mlx_mouse_move(data->mlx, data->win, x, y);
	}
}

static int	mouse_motion_handler(int x, int y, t_data *data)
{
	static int	old_x = WINDOW_W / 2;

	wrap_mouse_position(data, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		data->character.has_moved += rotate_character(data, -1);
	else if (x > old_x)
		data->character.has_moved += rotate_character(data, 1);
	old_x = x;
	return (0);
}

void	await_input(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, quit_program, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release_handler, data);
	if (BONUS)
		mlx_hook(data->win, MotionNotify, PointerMotionMask,
			mouse_motion_handler, data);
}
