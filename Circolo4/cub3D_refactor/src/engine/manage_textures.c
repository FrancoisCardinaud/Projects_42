/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/12 17:30:22 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Initialize the texture pixel buffer */
void	initialize_texture_pixels(t_data *game_data)
{
	int	i;

	if (game_data->texture_pixels)
		release_memory((void **)game_data->texture_pixels);
	game_data->texture_pixels = ft_calloc(game_data->win_height + 1,
			sizeof * game_data->texture_pixels);
	if (!game_data->texture_pixels)
		clean_exit(game_data, display_error_message(NULL, ERR_MALLOC, 1));
	i = 0;
	while (i < game_data->win_height)
	{
		game_data->texture_pixels[i] = ft_calloc(game_data->win_width + 1,
				sizeof * game_data->texture_pixels);
		if (!game_data->texture_pixels[i])
			clean_exit(game_data, display_error_message(NULL, ERR_MALLOC, 1));
		i++;
	}
}

/* Determine the texture index based on raycasting data */
static void	determine_texture_index(t_data *game_data, t_ray *raycast)
{
	if (raycast->side == 0)
	{
		if (raycast->dir_x < 0)
			game_data->texinfo.index = WEST;
		else
			game_data->texinfo.index = EAST;
	}
	else
	{
		if (raycast->dir_y > 0)
			game_data->texinfo.index = SOUTH;
		else
			game_data->texinfo.index = NORTH;
	}
}

/* Refresh the texture pixels based on the current frame */
void	refresh_texture_pixels(t_data *game_data, t_texinfo *texture_info,
		t_ray *raycast, int column)
{
	int	row;
	int	color;

	determine_texture_index(game_data, raycast);
	texture_info->x = (int)(raycast->wall_x * texture_info->size);
	if ((raycast->side == 0 && raycast->dir_x < 0) || (raycast->side == 1
			&& raycast->dir_y > 0))
		texture_info->x = texture_info->size - texture_info->x - 1;
	texture_info->step = 1.0 * texture_info->size / raycast->line_height;
	texture_info->pos = (raycast->draw_start - game_data->win_height / 2
			+ raycast->line_height / 2) * texture_info->step;
	row = raycast->draw_start;
	while (row < raycast->draw_end)
	{
		texture_info->y = (int)texture_info->pos & (texture_info->size - 1);
		texture_info->pos += texture_info->step;
		color = game_data->textures[texture_info->index][texture_info->size
			* texture_info->y + texture_info->x];
		if (texture_info->index == NORTH || texture_info->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game_data->texture_pixels[row][column] = color;
		row++;
	}
}
