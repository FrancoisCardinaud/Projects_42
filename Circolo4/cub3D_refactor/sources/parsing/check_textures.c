/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:29:02 by alexa             #+#    #+#             */
/*   Updated: 2024/04/07 04:35:16 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (display_error_message_validation(rgb[i], ERR_TEX_RGB_VAL, FAILURE));
		i++;
	}
	return (SUCCESS);
}

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	validate_textures(t_data *data, t_texture_data *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (display_error_message(data->mapinfo.path, ERR_TEX_MISSING, FAILURE));
	if (!textures->floor || !textures->ceiling)
		return (display_error_message(data->mapinfo.path, ERR_COLOR_MISSING, FAILURE));
	if (validate_file(textures->north, false) == FAILURE
		|| validate_file(textures->south, false) == FAILURE
		|| validate_file(textures->west, false) == FAILURE
		|| validate_file(textures->east, false) == FAILURE
		|| check_valid_rgb(textures->floor) == FAILURE
		|| check_valid_rgb(textures->ceiling) == FAILURE)
		return (FAILURE);
	textures->hex_floor = convert_rgb_to_hex(textures->floor);
	textures->hex_ceiling = convert_rgb_to_hex(textures->ceiling);
	return (SUCCESS);
}
