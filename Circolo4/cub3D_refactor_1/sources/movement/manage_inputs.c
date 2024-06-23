/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/23 17:41:25 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Handles key press events */
static int	handle_key_press(int key_code, t_data *game_data)
{
	if (key_code == XK_Escape)
		exit_game(game_data);
	if (key_code == XK_Left)
		game_data->player.rotate -= 1;
	if (key_code == XK_Right)
		game_data->player.rotate += 1;
	if (key_code == XK_w)
		game_data->player.move_y = 1;
	if (key_code == XK_a)
		game_data->player.move_x = -1;
	if (key_code == XK_s)
		game_data->player.move_y = -1;
	if (key_code == XK_d)
		game_data->player.move_x = 1;
	return (0);
}

/* Handles key release events */
static int	handle_key_release(int key_code, t_data *game_data)
{
	if (key_code == XK_Escape)
		exit_game(game_data);
	if (key_code == XK_w && game_data->player.move_y == 1)
		game_data->player.move_y = 0;
	if (key_code == XK_s && game_data->player.move_y == -1)
		game_data->player.move_y = 0;
	if (key_code == XK_a && game_data->player.move_x == -1)
		game_data->player.move_x += 1;
	if (key_code == XK_d && game_data->player.move_x == 1)
		game_data->player.move_x -= 1;
	if (key_code == XK_Left && game_data->player.rotate <= 1)
		game_data->player.rotate = 0;
	if (key_code == XK_Right && game_data->player.rotate >= -1)
		game_data->player.rotate = 0;
	return (0);
}

/* Adjusts mouse position to keep it within the window bounds */
static void	adjust_mouse_position(t_data *game_data, int mouse_x, int mouse_y)
{
	if (mouse_x > game_data->win_width - DIST_EDGE_MOUSE_WRAP)
	{
		mouse_x = DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(game_data->mlx, game_data->win, mouse_x, mouse_y);
	}
	if (mouse_x < DIST_EDGE_MOUSE_WRAP)
	{
		mouse_x = game_data->win_width - DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(game_data->mlx, game_data->win, mouse_x, mouse_y);
	}
}

/* Handles mouse motion events */
static int	handle_mouse_motion(int mouse_x, int mouse_y, t_data *game_data)
{
	static int	old_x = WIN_WIDTH / 2;

	adjust_mouse_position(game_data, mouse_x, mouse_y);
	if (mouse_x == old_x)
		return (0);
	else if (mouse_x < old_x)
		game_data->player.has_moved += rotate_player_direction(game_data, -1);
	else if (mouse_x > old_x)
		game_data->player.has_moved += rotate_player_direction(game_data, 1);
	old_x = mouse_x;
	return (0);
}

/* Initializes input event listeners */
void	listen_input(t_data *game_data)
{
	mlx_hook(game_data->win, ClientMessage, NoEventMask, exit_game, game_data);
	mlx_hook(game_data->win, KeyPress, KeyPressMask, handle_key_press, game_data);
	mlx_hook(game_data->win, KeyRelease, KeyReleaseMask, handle_key_release, game_data);
	if (BONUS)
		mlx_hook(game_data->win, MotionNotify, PointerMotionMask,
			handle_mouse_motion, game_data);
}
