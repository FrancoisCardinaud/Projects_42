/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:30:04 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/27 18:42:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Sets a pixel in the frame image based on the game data */
static void	set_pixel_in_frame(t_data *game_data, t_img *frame, int pixel_x, int pixel_y)
{
	if (game_data->texture_pixels[pixel_y][pixel_x] > 0)
		set_image_pixel(frame, pixel_x, pixel_y, game_data->texture_pixels[pixel_y][pixel_x]);
	else if (pixel_y < game_data->win_height / 2)
		set_image_pixel(frame, pixel_x, pixel_y, game_data->texinfo.hex_ceiling);
	else if (pixel_y < game_data->win_height - 1)
		set_image_pixel(frame, pixel_x, pixel_y, game_data->texinfo.hex_floor);
}

/* Draws the entire frame image */
static void	draw_frame(t_data *game_data)
{
	t_img	frame;
	int		pixel_x;
	int		pixel_y;
	double player_height = game_data->player.pos_z;

	frame.img = NULL;
	initialize_image(game_data, &frame, game_data->win_width, game_data->win_height);
	pixel_y = 0;
	while (pixel_y < game_data->win_height)
	{
		pixel_x = 0;
		while (pixel_x < game_data->win_width)
		{
			set_pixel_in_frame(game_data, &frame, pixel_x, pixel_y);
			pixel_x++;
		}
		pixel_y++;
	}
	mlx_put_image_to_window(game_data->mlx, game_data->win, frame.img, 0, 0);
	mlx_destroy_image(game_data->mlx, frame.img);
}

/* Performs raycasting and prepares the frame for rendering */
static void	perform_raycasting(t_data *game_data)
{
	initialize_texture_pixels(game_data);
	initialize_ray(&game_data->ray);
	perform_raycast(&game_data->player, game_data);
	draw_frame(game_data);
}

/* Displays images on the screen */
void	render_images(t_data *game_data)
{
	perform_raycasting(game_data);
	if (BONUS)
		draw_minimap(game_data);
}

/* Updates the frame based on player movement */
int	update_frame(t_data *game_data)
{
	game_data->player.has_moved += execute_player_move(game_data);
	if (game_data->player.has_moved == 0)
		return (0);
	render_images(game_data);
	return (0);
}
