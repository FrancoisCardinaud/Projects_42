/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:08:04 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Calculates the number of lines in the map */
static int	calculate_map_height(t_info *game_info, char **file_lines,
		int start_index)
{
	int	r;
	int	c;

	r = start_index;
	while (file_lines[r])
	{
		c = 0;
		while (file_lines[r][c])
		{
			if (file_lines[r][c] != ' ' && file_lines[r][c] != '\t'
				&& file_lines[r][c] != '\r' && file_lines[r][c] != '\v'
				&& file_lines[r][c] != '\f')
				break ;
			c++;
		}
		if (file_lines[r][c] != '1')
			break ;
		r++;
	}
	game_info->mapinfo.map_end_ind = r;
	return (r - start_index);
}

/* Populates the map array with the content from the file */
static int	populate_map_array(t_mapdata *m_info, char **m_array, int index)
{
	int	r;
	int	c;

	m_info->width = find_max_length(m_info, index);
	r = 0;
	while (r < m_info->height)
	{
		c = 0;
		m_array[r] = malloc(sizeof(char) * (m_info->width + 1));
		if (!m_array[r])
			return (disp_err_msg(NULL, MALLOC_ERROR, NOT_OK));
		while (m_info->file[index][c] && m_info->file[index][c] != '\n')
		{
			m_array[r][c] = m_info->file[index][c];
			c++;
		}
		while (c < m_info->width)
			m_array[r][c++] = '\0';
		r++;
		index++;
	}
	m_array[r] = NULL;
	return (OK);
}

/* Extracts the map information from the file */
static int	extract_map_info(t_info *game_info, char **file_lines,
		int start_index)
{
	int	height;

	height = calculate_map_height(game_info, file_lines, start_index);
	game_info->mapinfo.height = height;
	game_info->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!game_info->map)
	{
		disp_err_msg(NULL, MALLOC_ERROR, NOT_OK);
		return (NOT_OK);
	}
	if (populate_map_array(&game_info->mapinfo, game_info->map,
			start_index) == NOT_OK)
		return (NOT_OK);
	return (OK);
}

/* Converts spaces into walls in the map array */
static void	convert_spaces_to_walls(t_info *game_info)
{
	int	r;
	int	c;

	r = 0;
	while (game_info->map[r] != NULL)
	{
		c = 0;
		while (game_info->map[r][c] != '\0'
			&& (game_info->map[r][c] == ' '
				|| game_info->map[r][c] == '\t'
				|| game_info->map[r][c] == '\r'
				|| game_info->map[r][c] == '\v'
				|| game_info->map[r][c] == '\f'))
			c++;
		while (game_info->map[r][c] != '\0')
		{
			if (game_info->map[r][c] == ' '
				&& c != (int)ft_strlen(game_info->map[r]) - 1)
				game_info->map[r][c] = '1';
			c++;
		}
		r++;
	}
}

/* Generates the map from the given file lines */
int	generate_map(t_info *game_info, char **file_lines, int start_index)
{
	if (extract_map_info(game_info, file_lines, start_index) == NOT_OK)
		return (NOT_OK);
	convert_spaces_to_walls(game_info);
	return (OK);
}
