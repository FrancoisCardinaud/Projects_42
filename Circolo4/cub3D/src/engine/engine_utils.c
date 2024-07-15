/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 20:04:45 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Places a pixel at the specified coordinates in the image buffer */
void	set_image_pixel(t_img *img, int x, int y, int color)
{
	int	index;

	index = y * (img->size_line / 4) + x;
	img->addr[index] = color;
}

/* Renders a crosshair at the center of the screen */
void	display_crosshair(t_img *frame, t_info *game_info)
{
	int	center_x;
	int	center_y;
	int	size;
	int	color;
	int	offset;

	color = 0x9922FF44;
	center_x = game_info->window_width / 2;
	center_y = game_info->window_height / 2;
	size = 10;
	offset = -size;
	while (offset <= size)
	{
		if (offset < -4 || offset > 4 || offset == 0)
		{
			set_image_pixel(frame, center_x + offset, center_y, color);
			set_image_pixel(frame, center_x, center_y + offset, color);
		}
		offset++;
	}
}
