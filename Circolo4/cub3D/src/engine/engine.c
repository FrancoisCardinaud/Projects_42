/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:30:04 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 23:05:21 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Sets a pixel in the frame image based on the game data */
static void	draw_pixel_in_frame(t_info *info, t_img *frame, int x, int y)
{
	if (info->tex_pixels[y][x] > 0)
		insert_pixel(frame, x, y, info->tex_pixels[y][x]);
	else if (y < info->window_height / 2)
		insert_pixel(frame, x, y, info->texinfo.hex_ceiling);
	else if (y < info->window_height - 1)
		insert_pixel(frame, x, y, info->texinfo.hex_floor);
}

/* Renders the entire frame image */
static void	render_frame(t_info *info)
{
	t_img	frame;
	int		x;
	int		y;

	frame.img = NULL;
	initialize_image(info, &frame, info->window_width, info->window_height);
	y = 0;
	while (y < info->window_height)
	{
		x = 0;
		while (x < info->window_width)
		{
			draw_pixel_in_frame(info, &frame, x, y);
			x++;
		}
		y++;
	}
	display_crosshair(&frame, info);
	mlx_put_image_to_window(info->mlx, info->win, frame.img, 0, 0);
	mlx_destroy_image(info->mlx, frame.img);
}

/* Executes raycasting and prepares the frame for rendering */
static void	execute_raycasting(t_info *info)
{
	initialize_texture_pixels(info);
	initialize_ray(&info->ray);
	perform_raycast(&info->player, info);
	render_frame(info);
}

/* Displays images on the screen */
void	render_images(t_info *info)
{
	execute_raycasting(info);
}

/* Updates the frame based on player movement */
int	update_frame(t_info *info)
{
	info->player.has_moved += execute_player_move(info);
	if (info->player.has_moved == 0)
		return (0);
	render_images(info);
	return (0);
}
