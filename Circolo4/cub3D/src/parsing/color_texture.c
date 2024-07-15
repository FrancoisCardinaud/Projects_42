/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 23:05:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Populates the RGB array from the parts of the split string */
int	*populate_rgb_array(char **rgb_parts, int *rgb_array)
{
	int	part_index;

	part_index = 0;
	while (rgb_parts[part_index] != NULL)
	{
		rgb_array[part_index] = ft_atoi(rgb_parts[part_index]);
		if (rgb_array[part_index] == -1
			|| contains_no_digits(rgb_parts[part_index]))
		{
			release_memory((void **)rgb_parts);
			free(rgb_array);
			return (NULL);
		}
		part_index++;
	}
	release_memory((void **)rgb_parts);
	return (rgb_array);
}

/* Parses the RGB values from the input line */
static int	*parse_rgb_values(char *input_line)
{
	char	**rgb_parts;
	int		*rgb_array;
	int		part_count;

	rgb_parts = ft_split(input_line, ',');
	part_count = 0;
	while (rgb_parts[part_count] != NULL)
		part_count++;
	if (part_count != 3)
	{
		release_memory((void **)rgb_parts);
		return (NULL);
	}
	rgb_array = malloc(3 * sizeof(int));
	if (rgb_array == NULL)
	{
		disp_err_msg(NULL, MALLOC_ERROR, 0);
		release_memory((void **)rgb_parts);
		return (NULL);
	}
	return (populate_rgb_array(rgb_parts, rgb_array));
}

/* Assign the floor and ceiling colors from the input line */
int	assign_col_tex(t_info *game_info, t_texture_info *tex_info,
		char *input_line, int char_index)
{
	if (input_line[char_index + 1] && ft_isprint(input_line[char_index + 1]))
		return (disp_err_msg(game_info->mapinfo.path,
				INV_FLOOR_CEILING, ERROR));
	if (!tex_info->ceiling && input_line[char_index] == 'C')
	{
		tex_info->ceiling = parse_rgb_values(input_line + char_index + 1);
		if (!tex_info->ceiling)
			return (disp_err_msg(game_info->mapinfo.path,
					INV_CEILING_COLOR, ERROR));
	}
	else if (!tex_info->floor && input_line[char_index] == 'F')
	{
		tex_info->floor = parse_rgb_values(input_line + char_index + 1);
		if (!tex_info->floor)
			return (disp_err_msg(game_info->mapinfo.path,
					INV_FLOOR_COLOR, ERROR));
	}
	else
		return (disp_err_msg(game_info->mapinfo.path,
				INV_FLOOR_CEILING, ERROR));
	return (OK);
}
