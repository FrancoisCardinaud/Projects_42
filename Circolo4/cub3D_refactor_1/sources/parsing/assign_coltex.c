/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_coltex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/22 17:56:47 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Checks if the string contains no digits */
static bool	contains_no_digits(char *string)
{
	int		char_index;
	bool	found_no_digit;

	char_index = 0;
	found_no_digit = true;
	while (string[char_index])
	{
		if (ft_isdigit(string[char_index]) == 1)
			found_no_digit = false;
		char_index++;
	}
	return (found_no_digit);
}

/* Populates the RGB array from the parts of the split string */
static int	*populate_rgb_array(char **rgb_parts, int *rgb_array)
{
	int		part_index;

	part_index = -1;
	while (rgb_parts[++part_index])
	{
		rgb_array[part_index] = ft_atoi(rgb_parts[part_index]);
		if (rgb_array[part_index] == -1 || contains_no_digits(rgb_parts[part_index]) == true)
		{
			release_memory((void **)rgb_parts);
			free(rgb_array);
			return (0);
		}
	}
	release_memory((void **)rgb_parts);
	return (rgb_array);
}

/* Parses the RGB values from the input line */
static int	*parse_rgb_values(char *input_line)
{
	char	**rgb_parts;
	int		*rgb_array;
	int		parts_count;

	rgb_parts = ft_split(input_line, ',');
	parts_count = 0;
	while (rgb_parts[parts_count])
		parts_count++;
	if (parts_count != 3)
	{
		release_memory((void **)rgb_parts);
		return (0);
	}
	rgb_array = malloc(sizeof(int) * 3);
	if (!rgb_array)
	{
		display_error_message(NULL, ERR_MALLOC, 0);
		return (0);
	}
	return (populate_rgb_array(rgb_parts, rgb_array));
}

/* Assigns the floor and ceiling colors from the input line */
int	assign_color_textures(t_data *game_data, t_texinfo *texture_info, char *input_line, int char_index)
{
	if (input_line[char_index + 1] && ft_isprint(input_line[char_index + 1]))
		return (display_error_message(game_data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	if (!texture_info->ceiling && input_line[char_index] == 'C')
	{
		texture_info->ceiling = parse_rgb_values(input_line + char_index + 1);
		if (texture_info->ceiling == 0)
			return (display_error_message(game_data->mapinfo.path, ERR_COLOR_CEILING, ERR));
	}
	else if (!texture_info->floor && input_line[char_index] == 'F')
	{
		texture_info->floor = parse_rgb_values(input_line + char_index + 1);
		if (texture_info->floor == 0)
			return (display_error_message(game_data->mapinfo.path, ERR_COLOR_FLOOR, ERR));
	}
	else
		return (display_error_message(game_data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	return (SUCCESS);
}
