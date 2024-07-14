/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Validates the RGB values to ensure they are within the correct range */
static int	validate_rgb_values(int *rgb_values)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb_values[i] < 0 || rgb_values[i] > 255)
			return (display_error_with_value(rgb_values[i], TEX_RGB_VAL,
					NOT_OK));
		i++;
	}
	return (OK);
}

/* Converts an RGB array to a hexadecimal value */
static unsigned long	rgb_to_hex(int *rgb_array)
{
	unsigned long	hex_value;
	int				red;
	int				green;
	int				blue;

	red = rgb_array[0];
	green = rgb_array[1];
	blue = rgb_array[2];
	hex_value = ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
	return (hex_value);
}

/* Validates the textures' existence and correctness */
int	validate_textures(t_info *game_info, t_texinfo *texture_info)
{
	if (!texture_info->north || !texture_info->south || !texture_info->west
		|| !texture_info->east)
		return (display_error_message(game_info->mapinfo.path, TEX_MISSING,
				NOT_OK));
	if (!texture_info->floor || !texture_info->ceiling)
		return (display_error_message(game_info->mapinfo.path,
				COLOR_MISSING, NOT_OK));
	if (verify_file(texture_info->north, false) == NOT_OK
		|| verify_file(texture_info->south, false) == NOT_OK
		|| verify_file(texture_info->west, false) == NOT_OK
		|| verify_file(texture_info->east, false) == NOT_OK
		|| validate_rgb_values(texture_info->floor) == NOT_OK
		|| validate_rgb_values(texture_info->ceiling) == NOT_OK)
		return (NOT_OK);
	texture_info->hex_floor = rgb_to_hex(texture_info->floor);
	texture_info->hex_ceiling = rgb_to_hex(texture_info->ceiling);
	return (OK);
}
