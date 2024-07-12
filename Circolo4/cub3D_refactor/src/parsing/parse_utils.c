/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/12 17:29:53 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Checks if the string contains no digits */
bool	contains_no_digits(char *string)
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

/* Checks if the character is a whitespace */
int	is_whitespace(char character)
{
	if (character != ' ' && character != '\t' && character != '\r'
		&& character != '\n' && character != '\v' && character != '\f')
		return (FAILURE);
	else
		return (SUCCESS);
}

/* Counts the number of lines in the file */
int	count_lines_in_file(char *file_path)
{
	int		fd;
	char	*current_line;
	int		total_lines;

	total_lines = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		display_error_message(file_path, strerror(errno), errno);
	else
	{
		current_line = get_next_line(fd);
		while (current_line != NULL)
		{
			total_lines++;
			free(current_line);
			current_line = get_next_line(fd);
		}
		close(fd);
	}
	return (total_lines);
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
