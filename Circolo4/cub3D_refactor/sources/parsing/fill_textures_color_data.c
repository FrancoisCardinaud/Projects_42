/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_color_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:38:18 by fcardina          #+#    #+#             */
/*   Updated: 2024/03/09 22:38:19 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	no_digit(char *str)
{
	int		i;
	bool	found_no_digit;

	i = 0;
	found_no_digit = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			found_no_digit = false;
		i++;
	}
	return (found_no_digit);
}

static int	*copy_into_rgb_array(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || no_digit(rgb_to_convert[i]) == true)
		{
			free_memory((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	free_memory((void **)rgb_to_convert);
	return (rgb);
}

static int	*set_rgb_colors(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		free_memory((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		display_error_message(NULL, ERR_MALLOC, 0);
		return (0);
	}
	return (copy_into_rgb_array(rgb_to_convert, rgb));
}

int	fill_textures_color_data(t_data *data, t_texture_data *textures, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (display_error_message(data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	if (!textures->ceiling && line[j] == 'C')
	{
		textures->ceiling = set_rgb_colors(line + j + 1);
		if (textures->ceiling == 0)
			return (display_error_message(data->mapinfo.path, ERR_COLOR_CEILING, ERR));
	}
	else if (!textures->floor && line[j] == 'F')
	{
		textures->floor = set_rgb_colors(line + j + 1);
		if (textures->floor == 0)
			return (display_error_message(data->mapinfo.path, ERR_COLOR_FLOOR, ERR));
	}
	else
		return (display_error_message(data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	return (SUCCESS);
}
