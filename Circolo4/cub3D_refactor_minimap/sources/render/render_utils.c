/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/23 16:45:40 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Sets a pixel in the image buffer */
void	set_image_pixel(t_img *img, int pixel_x, int pixel_y, int pixel_color)
{
	int	pixel_index;

	pixel_index = pixel_y * (img->size_line / 4) + pixel_x;
	img->addr[pixel_index] = pixel_color;
}
