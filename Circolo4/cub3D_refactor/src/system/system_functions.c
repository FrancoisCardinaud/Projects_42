/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Displays an error message with an optional detail and code */
int	display_error_message(char *error_detail, char *display_error_message,
		int error_code)
{
	ft_putstr_fd("\e[31mcub3D: Error: \e[0m", 2);
	if (error_detail)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error_detail, 2);
	}
	if (display_error_message)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(display_error_message, 2);
	}
	ft_putstr_fd("\n", 2);
	return (error_code);
}

/* Displays an error message with an integer detail and code */
int	display_error_with_value(int error_detail, char *display_error_message,
		int error_code)
{
	ft_putstr_fd("\e[31mcub3D: Error: \e[0m", 2);
	ft_putnbr_fd(error_detail, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(display_error_message, 2);
	ft_putstr_fd("\n", 2);
	return (error_code);
}

/* Gracefully exits the game, freeing resources and closing the window */
void	clean_exit(t_info *game_info, int exit_code)
{
	if (!game_info)
		exit(exit_code);
	if (game_info->win && game_info->mlx)
		mlx_destroy_window(game_info->mlx, game_info->win);
	if (game_info->mlx)
	{
		mlx_destroy_display(game_info->mlx);
		mlx_loop_end(game_info->mlx);
		free(game_info->mlx);
	}
	release_resources(game_info);
	exit(exit_code);
}

/* Handles the quit event for the game */
int	exit_game(t_info *game_info)
{
	clean_exit(game_info, 0);
	return (0);
}
