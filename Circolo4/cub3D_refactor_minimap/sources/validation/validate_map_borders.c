/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_borders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/23 17:47:20 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Validates the top or bottom border of the map */
static int	validate_top_or_bottom_border(char **map_array, int row, int col)
{
	if (!map_array || !map_array[row] || !map_array[row][col])
		return (FAILURE);
	while (map_array[row][col] == ' ' || map_array[row][col] == '\t'
		|| map_array[row][col] == '\r' || map_array[row][col] == '\v'
		|| map_array[row][col] == '\f')
		col++;
	while (map_array[row][col])
	{
		if (map_array[row][col] != '1')
			return (FAILURE);
		col++;
	}
	return (SUCCESS);
}

/* Verifies that the map is enclosed by walls on all sides */
int	validate_map_borders(t_mapinfo *map_info, char **map_array)
{
	int	row;
	int	col;

	if (validate_top_or_bottom_border(map_array, 0, 0) == FAILURE)
		return (FAILURE);
	row = 1;
	while (row < (map_info->height - 1))
	{
		col = ft_strlen(map_array[row]) - 1;
		if (map_array[row][col] != '1')
			return (FAILURE);
		row++;
	}
	if (validate_top_or_bottom_border(map_array, row, 0) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
