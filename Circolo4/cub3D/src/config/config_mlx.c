/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:33:53 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 22:08:18 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Resets the image structure */
void	reset_image(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}

/* Sets up a new image in the given dimensions */
void	initialize_image(t_info *game_info, t_img *img, int width, int height)
{
	reset_image(img);
	img->img = mlx_new_image(game_info->mlx, width, height);
	if (img->img == NULL)
		total_exit(game_info, disp_err_msg("mlx",
				UNABLE_CREATE_MLX_IMAGE, 1));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
}

/* Loads a texture image from a file */
void	initialize_texture_image(t_info *game_info, t_img *img, char *file_path)
{
	reset_image(img);
	img->img = mlx_xpm_file_to_image(game_info->mlx, file_path,
			&game_info->texinfo.size, &game_info->texinfo.size);
	if (img->img == NULL)
		total_exit(game_info, disp_err_msg("mlx",
				UNABLE_CREATE_MLX_IMAGE, 1));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
}

/* Initializes the MLX graphics context and window */
void	initialize_graphics(t_info *game_info)
{
	game_info->mlx = mlx_init();
	if (!game_info->mlx)
		total_exit(game_info, disp_err_msg("mlx", UNABLE_START_MLX,
				1));
	game_info->win = mlx_new_window(game_info->mlx, WINDOW_W, WINDOW_H,
			"Cub3D");
	if (!game_info->win)
		total_exit(game_info, disp_err_msg("mlx",
				UNABLE_CREATE_MLX_WINDOW, 1));
}
