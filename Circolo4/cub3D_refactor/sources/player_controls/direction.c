/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/03 17:35:53 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Sets the player's direction for north and south */
void	set_player_north_south(t_player *player_data)
{
	if (player_data->dir == 'S')
	{
		player_data->dir_x = 0;
		player_data->dir_y = 1;
		player_data->plane_vector_x = -0.8;
		player_data->plane_vector_y = 0;
	}
	else if (player_data->dir == 'N')
	{
		player_data->dir_x = 0;
		player_data->dir_y = -1;
		player_data->plane_vector_x = 0.8;
		player_data->plane_vector_y = 0;
	}
}

/* Sets the player's direction for east and west */
void	set_player_east_west(t_player *player_data)
{
	if (player_data->dir == 'W')
	{
		player_data->dir_x = -1;
		player_data->dir_y = 0;
		player_data->plane_vector_x = 0;
		player_data->plane_vector_y = -0.8;
	}
	else if (player_data->dir == 'E')
	{
		player_data->dir_x = 1;
		player_data->dir_y = 0;
		player_data->plane_vector_x = 0;
		player_data->plane_vector_y = 0.8;
	}
}
