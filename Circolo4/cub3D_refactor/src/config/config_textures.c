/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:34:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/13 18:21:56 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Loads an XPM image file into a buffer */
static int	*convert_xpm(t_data *game_data, char *file_path)
{
	t_img	temp_img;
	int		*texture_buffer;
	int		width;
	int		height;

	initialize_texture_image(game_data, &temp_img, file_path);
	texture_buffer = ft_calloc(1, sizeof(*texture_buffer)
			* game_data->texinfo.size * game_data->texinfo.size);
	if (!texture_buffer)
		clean_exit(game_data, display_error_message(NULL, ERR_MALLOC, 1));
	height = 0;
	while (height < game_data->texinfo.size)
	{
		width = 0;
		while (width < game_data->texinfo.size)
		{
			texture_buffer[height * game_data->texinfo.size
				+ width] = temp_img.addr[height * game_data->texinfo.size
				+ width];
			++width;
		}
		height++;
	}
	mlx_destroy_image(game_data->mlx, temp_img.img);
	return (texture_buffer);
}

/* Initializes textures from XPM files */
void	initialize_textures(t_data *game_data)
{
	game_data->textures = ft_calloc(5, sizeof(*game_data->textures));
	if (!game_data->textures)
		clean_exit(game_data, display_error_message(NULL, ERR_MALLOC, 1));
	game_data->textures[NORTH] = convert_xpm(game_data,
			game_data->texinfo.north);
	game_data->textures[SOUTH] = convert_xpm(game_data,
			game_data->texinfo.south);
	game_data->textures[EAST] = convert_xpm(game_data,
			game_data->texinfo.east);
	game_data->textures[WEST] = convert_xpm(game_data,
			game_data->texinfo.west);
}

/* Initializes the texture information structure */
void	initialize_texture_info(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
