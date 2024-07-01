/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/01 19:39:33 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Sets the player's direction for north and south */
static void	set_player_north_south(t_player *player_data)
{
	if (player_data->dir == 'S')
	{
		player_data->dir_x = 0;
		player_data->dir_y = 1;
		player_data->plane_x = -0.66;
		player_data->plane_y = 0;
	}
	else if (player_data->dir == 'N')
	{
		player_data->dir_x = 0;
		player_data->dir_y = -1;
		player_data->plane_x = 0.66;
		player_data->plane_y = 0;
	}
}

/* Sets the player's direction for east and west */
static void	set_player_east_west(t_player *player_data)
{
	if (player_data->dir == 'W')
	{
		player_data->dir_x = -1;
		player_data->dir_y = 0;
		player_data->plane_x = 0;
		player_data->plane_y = -0.66;
	}
	else if (player_data->dir == 'E')
	{
		player_data->dir_x = 1;
		player_data->dir_y = 0;
		player_data->plane_x = 0;
		player_data->plane_y = 0.66;
	}
}

/* Initializes the player's direction based on the initial orientation */
void	set_player_direction(t_data *game_data)
{
	set_player_north_south(&game_data->player);
	set_player_east_west(&game_data->player);
}
