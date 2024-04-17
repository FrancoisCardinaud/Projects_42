/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:31:14 by fcardina          #+#    #+#             */
/*   Updated: 2024/04/06 19:55:56 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_character_north_south(t_character *character)
{
	if (character->dir == 'S')
	{
		character->dir_x = 0;
		character->dir_y = 1;
		character->plane_x = -0.66;
		character->plane_y = 0;
	}
	else if (character->dir == 'N')
	{
		character->dir_x = 0;
		character->dir_y = -1;
		character->plane_x = 0.66;
		character->plane_y = 0;
	}
	else
		return ;
}

static void	init_character_east_west(t_character *character)
{
	if (character->dir == 'W')
	{
		character->dir_x = -1;
		character->dir_y = 0;
		character->plane_x = 0;
		character->plane_y = -0.66;
	}
	else if (character->dir == 'E')
	{
		character->dir_x = 1;
		character->dir_y = 0;
		character->plane_x = 0;
		character->plane_y = 0.66;
	}
	else
		return ;
}

void	set_character_direction(t_data *data)
{
	init_character_north_south(&data->character);
	init_character_east_west(&data->character);
}
