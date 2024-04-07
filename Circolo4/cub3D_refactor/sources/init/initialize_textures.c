/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:34:03 by mcombeau          #+#    #+#             */
/*   Updated: 2024/04/06 19:52:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	initialize_texture_image(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texture_data.size * data->texture_data.size);
	if (!buffer)
		exit_cleanup(data, display_error_message(NULL, ERR_MALLOC, 1));
	y = 0;
	while (y < data->texture_data.size)
	{
		x = 0;
		while (x < data->texture_data.size)
		{
			buffer[y * data->texture_data.size + x]
				= tmp.addr[y * data->texture_data.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	initialize_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		exit_cleanup(data, display_error_message(NULL, ERR_MALLOC, 1));
	data->textures[NORTH] = xpm_to_img(data, data->texture_data.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texture_data.south);
	data->textures[EAST] = xpm_to_img(data, data->texture_data.east);
	data->textures[WEST] = xpm_to_img(data, data->texture_data.west);
}

void	initialize_texture_data(t_texture_data *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEXTURE_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
