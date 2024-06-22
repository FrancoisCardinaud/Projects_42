/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_program.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/22 15:39:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Gracefully exits the game, freeing resources and closing the window */
void	clean_exit(t_data *game_data, int exit_code)
{
	if (!game_data)
		exit(exit_code);
	if (game_data->win && game_data->mlx)
		mlx_destroy_window(game_data->mlx, game_data->win);
	if (game_data->mlx)
	{
		mlx_destroy_display(game_data->mlx);
		mlx_loop_end(game_data->mlx);
		free(game_data->mlx);
	}
	release_resources(game_data);
	exit(exit_code);
}

/* Handles the quit event for the game */
int	exit_game(t_data *game_data)
{
	clean_exit(game_data, 0);
	return (0);
}
