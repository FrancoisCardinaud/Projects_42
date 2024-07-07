/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:33:53 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/07 14:25:50 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
void	initialize_image(t_data *game_data, t_img *img, int width, int height)
{
	reset_image(img);
	img->img = mlx_new_image(game_data->mlx, width, height);
	if (img->img == NULL)
		clean_exit(game_data, display_error_message("mlx", ERR_MLX_IMG, 1));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
}

/* Loads a texture image from a file */
void	initialize_texture_image(t_data *game_data, t_img *img, char *file_path)
{
	reset_image(img);
	img->img = mlx_xpm_file_to_image(game_data->mlx, file_path, &game_data->texinfo.size,
			&game_data->texinfo.size);
	if (img->img == NULL)
		clean_exit(game_data, display_error_message("mlx", ERR_MLX_IMG, 1));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->size_line, &img->endian);
}

/* Initializes the MLX graphics context and window */
void	initialize_graphics(t_data *game_data)
{
	game_data->mlx = mlx_init();
	if (!game_data->mlx)
		clean_exit(game_data, display_error_message("mlx", ERR_MLX_START, 1));
	game_data->win = mlx_new_window(game_data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game_data->win)
		clean_exit(game_data, display_error_message("mlx", ERR_MLX_WIN, 1));
}
