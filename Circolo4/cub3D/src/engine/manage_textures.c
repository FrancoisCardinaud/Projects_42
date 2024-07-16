/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 17:41:35 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Initialize the texture pixel buffer */
void	initialize_texture_pixels(t_info *game_info)
{
	int	i;

	if (game_info->tex_pixels != NULL)
	{
		release_memory((void **)game_info->tex_pixels);
	}
	game_info->tex_pixels = ft_calloc(game_info->window_height + 1,
			sizeof(*game_info->tex_pixels));
	if (game_info->tex_pixels == NULL)
	{
		total_exit(game_info, disp_err_msg(NULL, MALLOC_ERROR, 1));
	}
	i = 0;
	while (i < game_info->window_height)
	{
		game_info->tex_pixels[i] = ft_calloc(game_info->window_width + 1,
				sizeof(*game_info->tex_pixels));
		if (game_info->tex_pixels[i] == NULL)
		{
			total_exit(game_info, disp_err_msg(NULL, MALLOC_ERROR, 1));
		}
		i++;
	}
}

/* Determine the texture index based on raycasting data */
static void	determine_texture_index(t_info *game_info, t_ray *raycast)
{
	if (raycast->side == 0)
	{
		if (raycast->direction_x < 0)
			game_info->texinfo.index = WE;
		else
			game_info->texinfo.index = EA;
	}
	else
	{
		if (raycast->direction_y > 0)
			game_info->texinfo.index = SO;
		else
			game_info->texinfo.index = NO;
	}
}

/* Refresh the texture pixels based on the current frame */
void	refresh_texture_pixels(t_info *game_info, t_texture_info *tex_info,
		t_ray *raycast, int column)
{
	int	row;
	int	color;

	determine_texture_index(game_info, raycast);
	tex_info->x = (int)(raycast->wall_hor * (double)tex_info->size);
	if ((raycast->side == 0 && raycast->direction_x < 0) || (raycast->side == 1
			&& raycast->direction_y > 0))
		tex_info->x = tex_info->size - tex_info->x - 1;
	tex_info->step = 1.0 * tex_info->size / raycast->line_h;
	tex_info->pos = (raycast->cast_start - game_info->window_height / 2
			+ raycast->line_h / 2) * tex_info->step;
	row = raycast->cast_start;
	while (row < raycast->cast_end)
	{
		tex_info->y = (int)tex_info->pos & (tex_info->size - 1);
		tex_info->pos += tex_info->step;
		color = game_info->textures[tex_info->index][tex_info->size
			* tex_info->y + tex_info->x];
		if (tex_info->index == NO || tex_info->index == EA)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game_info->tex_pixels[row][column] = color;
		row++;
	}
}
