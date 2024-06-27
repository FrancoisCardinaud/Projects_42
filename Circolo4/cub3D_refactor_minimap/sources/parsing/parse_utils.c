/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/23 17:46:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Checks if the character is a whitespace */
int	is_whitespace(char character)
{
	if (character != ' ' && character != '\t' && character != '\r'
		&& character != '\n' && character != '\v' && character != '\f')
		return (FAILURE);
	else
		return (SUCCESS);
}

/* Finds the length of the longest line in the map file */
size_t	find_max_length(t_mapinfo *map_info, int line_index)
{
	size_t	longest_length;

	longest_length = ft_strlen(map_info->file[line_index]);
	while (map_info->file[line_index])
	{
		if (ft_strlen(map_info->file[line_index]) > longest_length)
			longest_length = ft_strlen(map_info->file[line_index]);
		line_index++;
	}
	return (longest_length);
}
