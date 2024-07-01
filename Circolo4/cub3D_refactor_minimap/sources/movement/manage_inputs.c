/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/01 20:02:01 by fcardina         ###   ########.fr       */
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
	if (key_code == XK_Shift_L)
        game_data->player.running = 1;
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
	if (key_code == XK_Shift_L)
        game_data->player.running = 0;
	return (0);
}

/* Initializes input event listeners */
void	listen_input(t_data *game_data)
{
	mlx_hook(game_data->win, ClientMessage, NoEventMask, exit_game, game_data);
	mlx_hook(game_data->win, KeyPress, KeyPressMask, handle_key_press, game_data);
	mlx_hook(game_data->win, KeyRelease, KeyReleaseMask, handle_key_release, game_data);
}
