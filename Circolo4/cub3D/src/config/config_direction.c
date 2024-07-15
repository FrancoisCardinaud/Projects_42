/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 23:05:29 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Sets the player's direction for north and south */
void	config_player_north_south(t_player *player_data)
{
	if (player_data->dir == 'N')
	{
		player_data->dir_x = 0;
		player_data->dir_y = -1;
		player_data->plane_vector_x = 0.8;
		player_data->plane_vector_y = 0;
	}
	else if (player_data->dir == 'S')
	{
		player_data->dir_x = 0;
		player_data->dir_y = 1;
		player_data->plane_vector_x = -0.8;
		player_data->plane_vector_y = 0;
	}
}

/* Sets the player's direction for east and west */
void	config_player_east_west(t_player *player_data)
{
	if (player_data->dir == 'E')
	{
		player_data->dir_x = 1;
		player_data->dir_y = 0;
		player_data->plane_vector_x = 0;
		player_data->plane_vector_y = 0.8;
	}
	else if (player_data->dir == 'W')
	{
		player_data->dir_x = -1;
		player_data->dir_y = 0;
		player_data->plane_vector_x = 0;
		player_data->plane_vector_y = -0.8;
	}
}
