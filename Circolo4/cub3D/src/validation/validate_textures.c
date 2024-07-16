/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:07:43 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Converts an RGB array to a hexadecimal value */
static unsigned long	rgb_to_hex_conversion(int *rgb_array)
{
	unsigned long	hex_value;
	int				red;
	int				green;
	int				blue;

	red = rgb_array[0] & 0xff;
	green = rgb_array[1] & 0xff;
	blue = rgb_array[2] & 0xff;
	hex_value = (red << 16) + (green << 8) + blue;
	return (hex_value);
}

/* Validates the RGB values to ensure they are within the correct range */
static int	validate_rgb_values(int *rgb_values)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb_values[i] < 0 || rgb_values[i] > 255)
			return (display_error_with_value(rgb_values[i],
					INV_TEXTURE_RGB_VALUE, NOT_OK));
		i++;
	}
	return (OK);
}

/* Validates the textures' existence and correctness */
int	validate_textures(t_info *game_info, t_texture_info *tex_info)
{
	if (!tex_info->north || !tex_info->south || !tex_info->west
		|| !tex_info->east)
		return (disp_err_msg(game_info->mapinfo.path, MISSING_TEXTURE, NOT_OK));
	if (!tex_info->floor || !tex_info->ceiling)
		return (disp_err_msg(game_info->mapinfo.path, COLOR_NOT_FOUND, NOT_OK));
	if (validate_file(tex_info->north, false) == NOT_OK
		|| validate_file(tex_info->south, false) == NOT_OK
		|| validate_file(tex_info->west, false) == NOT_OK
		|| validate_file(tex_info->east, false) == NOT_OK)
		return (NOT_OK);
	if (validate_rgb_values(tex_info->floor) == NOT_OK
		|| validate_rgb_values(tex_info->ceiling) == NOT_OK)
		return (NOT_OK);
	tex_info->floor_hex = rgb_to_hex_conversion(tex_info->floor);
	tex_info->ceiling_hex = rgb_to_hex_conversion(tex_info->ceiling);
	return (OK);
}
