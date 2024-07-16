/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:34:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 17:41:39 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Loads an XPM image file into a buffer */
static int	*convert_xpm(t_info *game_info, char *file_path)
{
	t_img	temp_img;
	int		*texture_buffer;
	int		width;
	int		height;

	initialize_texture_image(game_info, &temp_img, file_path);
	texture_buffer = ft_calloc(1, sizeof(*texture_buffer)
			* game_info->texinfo.size * game_info->texinfo.size);
	if (!texture_buffer)
		total_exit(game_info, disp_err_msg(NULL, MALLOC_ERROR, 1));
	height = 0;
	while (height < game_info->texinfo.size)
	{
		width = 0;
		while (width < game_info->texinfo.size)
		{
			texture_buffer[height * game_info->texinfo.size
				+ width] = temp_img.addr[height * game_info->texinfo.size
				+ width];
			++width;
		}
		height++;
	}
	mlx_destroy_image(game_info->mlx, temp_img.img);
	return (texture_buffer);
}

/* Initializes textures from XPM files */
void	initialize_textures(t_info *game_info)
{
	game_info->textures = ft_calloc(5, sizeof(*game_info->textures));
	if (!game_info->textures)
		total_exit(game_info, disp_err_msg(NULL, MALLOC_ERROR, 1));
	game_info->textures[NO] = convert_xpm(game_info,
			game_info->texinfo.north);
	game_info->textures[SO] = convert_xpm(game_info,
			game_info->texinfo.south);
	game_info->textures[EA] = convert_xpm(game_info,
			game_info->texinfo.east);
	game_info->textures[WE] = convert_xpm(game_info,
			game_info->texinfo.west);
}

/* Initializes the texture information structure */
void	initialize_texture_info(t_texture_info *tex)
{
	tex->x = 0;
	tex->y = 0;
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->east = NULL;
	tex->size = 64;
	tex->step = 0.0;
	tex->pos = 0.0;
	tex->floor = 0;
	tex->ceiling = 0;
	tex->floor_hex = 0x0;
	tex->ceiling_hex = 0x0;
}
