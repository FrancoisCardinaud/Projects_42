/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:33:53 by mcombeau          #+#    #+#             */
/*   Updated: 2024/04/06 19:51:11 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_img(t_data *data, t_img *image, int width, int height)
{
	clean_initialize_img(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		exit_cleanup(data, display_error_message("mlx", ERR_MLX_IMG, 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	initialize_texture_image(t_data *data, t_img *image, char *path)
{
	clean_initialize_img(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texture_data.size,
			&data->texture_data.size);
	if (image->img == NULL)
		exit_cleanup(data, display_error_message("mlx", ERR_MLX_IMG, 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	initialize_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_cleanup(data, display_error_message("mlx", ERR_MLX_START, 1));
	data->win = mlx_new_window(data->mlx, WINDOW_W, WINDOW_H, "Cub3D");
	if (!data->win)
		exit_cleanup(data, display_error_message("mlx", ERR_MLX_WIN, 1));
	if (BONUS)
		mlx_mouse_move(data->mlx, data->win, data->win_width / 2,
			data->win_height / 2);
	return ;
}
