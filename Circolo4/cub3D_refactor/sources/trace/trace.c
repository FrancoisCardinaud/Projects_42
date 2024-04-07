/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:30:04 by mcombeau          #+#    #+#             */
/*   Updated: 2024/04/06 19:51:47 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(image, x, y, data->texture_data.hex_ceiling);
	else if (y < data->win_height -1)
		set_image_pixel(image, x, y, data->texture_data.hex_floor);
}

static void	trace_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	initialize_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

static void	trace_raycast(t_data *data)
{
	initialize_texture_pixels(data);
	initialize_rays(&data->ray);
	perform_raycasting(&data->player, data);
	trace_frame(data);
}

void	trace_images(t_data *data)
{
	trace_raycast(data);
	if (BONUS)
		trace_minimap(data);
}

int	trace(t_data *data)
{
	data->player.has_moved += move_character(data);
	if (data->player.has_moved == 0)
		return (0);
	trace_images(data);
	return (0);
}
