/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:33:30 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:07:53 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Releases allocated memory for texture information */
static void	release_texture_info(t_texture_info *tex_info)
{
	if (tex_info->north)
		free(tex_info->north);
	if (tex_info->south)
		free(tex_info->south);
	if (tex_info->west)
		free(tex_info->west);
	if (tex_info->east)
		free(tex_info->east);
	if (tex_info->floor)
		free(tex_info->floor);
	if (tex_info->ceiling)
		free(tex_info->ceiling);
}

/* Releases allocated memory for a given array */
void	release_memory(void **memory_array)
{
	size_t	index;

	index = 0;
	while (memory_array[index])
	{
		free(memory_array[index]);
		index++;
	}
	if (memory_array)
	{
		free(memory_array);
		memory_array = NULL;
	}
}

/* Releases allocated memory for the map */
static void	release_map_memory(t_info *game_info)
{
	if (game_info->mapinfo.fd > 0)
		close(game_info->mapinfo.fd);
	if (game_info->mapinfo.file)
		release_memory((void **)game_info->mapinfo.file);
	if (game_info->map)
		release_memory((void **)game_info->map);
}

/* Releases all allocated resources and returns NOT_OK */
int	release_memory_resources(t_info *game_info)
{
	if (game_info->textures)
		release_memory((void **)game_info->textures);
	if (game_info->tex_pixels)
		release_memory((void **)game_info->tex_pixels);
	release_texture_info(&game_info->texinfo);
	release_map_memory(game_info);
	return (NOT_OK);
}
