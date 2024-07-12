/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/12 17:30:26 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Sets a pixel in the image buffer */
void	set_image_pixel(t_img *img, int pixel_x, int pixel_y, int pixel_color)
{
	int	pixel_index;

	pixel_index = pixel_y * (img->size_line / 4) + pixel_x;
	img->addr[pixel_index] = pixel_color;
}

void	display_crosshair(t_img *frame, t_data *game_data)
{
	int	center_x;
	int	center_y;
	int	crosshair_size;
	int	color;
	int	i;

	color = 0x9922FF44;
	center_x = game_data->win_width / 2;
	center_y = game_data->win_height / 2;
	crosshair_size = 10;
	i = -crosshair_size;
	while (i <= crosshair_size)
	{
		if (i < -4 || i > 4 || i == 0)
		{
			set_image_pixel(frame, center_x + i, center_y, color);
			set_image_pixel(frame, center_x, center_y + i, color);
		}
		i++;
	}
}
