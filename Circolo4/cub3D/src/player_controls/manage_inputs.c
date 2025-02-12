/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:07:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Handles key release events */
static int	handle_key_release(int input, t_info *game_info)
{
	if (input == XK_Escape)
		exit_game(game_info);
	if ((input == XK_w || input == XK_z) && game_info->player.move_ver == 1)
		game_info->player.move_ver = 0;
	if (input == XK_s && game_info->player.move_ver == -1)
		game_info->player.move_ver = 0;
	if ((input == XK_a || input == XK_q) && game_info->player.move_hor == -1)
		game_info->player.move_hor += 1;
	if (input == XK_d && game_info->player.move_hor == 1)
		game_info->player.move_hor -= 1;
	if (input == XK_Left && game_info->player.rotation <= 1)
		game_info->player.rotation = 0;
	if (input == XK_Right && game_info->player.rotation >= -1)
		game_info->player.rotation = 0;
	if (input == XK_Shift_L)
		game_info->player.running = 0;
	return (0);
}

/* Handles key press events */
static int	handle_key_press(int input, t_info *game_info)
{
	if (input == XK_Escape)
		exit_game(game_info);
	if (input == XK_Left)
		game_info->player.rotation -= 1;
	if (input == XK_Right)
		game_info->player.rotation += 1;
	if (input == XK_w || input == XK_z)
		game_info->player.move_ver = 1;
	if (input == XK_a || input == XK_q)
		game_info->player.move_hor = -1;
	if (input == XK_s)
		game_info->player.move_ver = -1;
	if (input == XK_d)
		game_info->player.move_hor = 1;
	if (input == XK_Shift_L)
		game_info->player.running = 1;
	return (0);
}

/* Initializes input event listeners */
void	listen_input(t_info *game_info)
{
	mlx_hook(game_info->win, ClientMessage, NoEventMask, exit_game, game_info);
	mlx_hook(game_info->win, KeyPress, KeyPressMask, handle_key_press,
		game_info);
	mlx_hook(game_info->win, KeyRelease, KeyReleaseMask, handle_key_release,
		game_info);
}
