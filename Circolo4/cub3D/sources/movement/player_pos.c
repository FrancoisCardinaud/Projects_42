/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:57:06 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_pos_wall_collision(t_info *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	is_valid_pos_in_map(t_info *data, double x, double y)
{
	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->mapinfo.height -0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_info *data, double x, double y)
{
	if (!BONUS && is_valid_pos_in_map(data, x, y))
		return (true);
	if (BONUS && is_valid_pos_wall_collision(data, x, y))
		return (true);
	return (false);
}

int	validate_move(t_info *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
