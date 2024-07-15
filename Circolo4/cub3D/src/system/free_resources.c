/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:33:30 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:09:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

/* Releases allocated memory for texture information */
static void	release_texture_info(t_texinfo *texture_info)
{
	if (texture_info->north)
		free(texture_info->north);
	if (texture_info->south)
		free(texture_info->south);
	if (texture_info->west)
		free(texture_info->west);
	if (texture_info->east)
		free(texture_info->east);
	if (texture_info->floor)
		free(texture_info->floor);
	if (texture_info->ceiling)
		free(texture_info->ceiling);
}

/* Releases allocated memory for the map */
static void	release_map(t_info *game_info)
{
	if (game_info->mapinfo.fd > 0)
		close(game_info->mapinfo.fd);
	if (game_info->mapinfo.file)
		release_memory((void **)game_info->mapinfo.file);
	if (game_info->map)
		release_memory((void **)game_info->map);
}

/* Releases all allocated resources and returns NOT_OK */
int	release_resources(t_info *game_info)
{
	if (game_info->textures)
		release_memory((void **)game_info->textures);
	if (game_info->texture_pixels)
		release_memory((void **)game_info->texture_pixels);
	release_texture_info(&game_info->texinfo);
	release_map(game_info);
	return (NOT_OK);
}
