/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:39:50 by fcardina          #+#    #+#             */
/*   Updated: 2024/03/10 12:44:04 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_initialize_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	initialize_rays(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

static void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->line_count = 0;
	mapinfo->path = NULL;
	mapinfo->file = NULL;
	mapinfo->height = 0;
	mapinfo->width = 0;
	mapinfo->index_end_of_map = 0;
}

static void	init_character(t_character *character)
{
	character->dir = '\0';
	character->pos_x = 0.0;
	character->pos_y = 0.0;
	character->dir_x = 0.0;
	character->dir_y = 0.0;
	character->plane_x = 0.0;
	character->plane_y = 0.0;
	character->has_moved = 0;
	character->move_x = 0;
	character->move_y = 0;
	character->rotate = 0;
}

void	initialize_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WINDOW_H;
	data->win_width = WINDOW_W;
	init_character(&data->character);
	initialize_texture_data(&data->texture_data);
	data->map = NULL;
	init_mapinfo(&data->mapinfo);
	clean_initialize_img(&data->minimap);
	data->texture_pixels = NULL;
	data->textures = NULL;
}
