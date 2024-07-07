/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/07 04:38:38 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Handles key press events */
static int	handle_key_press(int input, t_data *game_data)
{
	if (input == XK_Escape)
		exit_game(game_data);
	if (input == XK_Left)
		game_data->player.rotate -= 1;
	if (input == XK_Right)
		game_data->player.rotate += 1;
	if (input == XK_w || input == XK_z)
		game_data->player.move_y = 1;
	if (input == XK_a || input == XK_q)
		game_data->player.move_x = -1;
	if (input == XK_s)
		game_data->player.move_y = -1;
	if (input == XK_d)
		game_data->player.move_x = 1;
	if (input == XK_Shift_L)
        game_data->player.running = 1;
	return (0);
}

/* Handles key release events */
static int	handle_key_release(int input, t_data *game_data)
{
	if (input == XK_Escape)
		exit_game(game_data);
	if ((input == XK_w || input == XK_z) && game_data->player.move_y == 1)
		game_data->player.move_y = 0;
	if (input == XK_s && game_data->player.move_y == -1)
		game_data->player.move_y = 0;
	if ((input == XK_a || input == XK_q) && game_data->player.move_x == -1)
		game_data->player.move_x += 1;
	if (input == XK_d && game_data->player.move_x == 1)
		game_data->player.move_x -= 1;
	if (input == XK_Left && game_data->player.rotate <= 1)
		game_data->player.rotate = 0;
	if (input == XK_Right && game_data->player.rotate >= -1)
		game_data->player.rotate = 0;
	if (input == XK_Shift_L)
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
