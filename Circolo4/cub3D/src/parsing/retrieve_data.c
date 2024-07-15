/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 21:18:54 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Finds the length of the longest line in the map file */
size_t	find_max_length(t_mapinfo *map_info, int line_index)
{
	size_t	current_length;
	size_t	max_length;

	max_length = 0;
	while (map_info->file[line_index])
	{
		current_length = ft_strlen(map_info->file[line_index]);
		if (current_length > max_length)
			max_length = current_length;
		line_index++;
	}
	return (max_length);
}

/* Extracts the texture path from the input line */
static char	*extract_texture_path(char *line, int index)
{
	int		start;
	int		i;
	char	*path;

	while (line[index] && (line[index] == ' ' || line[index] == '\t'))
		index++;
	start = index;
	while (line[start] && line[start] != ' ' && line[start] != '\t')
		start++;
	path = (char *)malloc(sizeof(char) * (start - index + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (index < start && line[index] && line[index] != '\n')
		path[i++] = line[index++];
	path[i] = '\0';
	while (line[index] && (line[index] == ' ' || line[index] == '\t'))
		index++;
	if (line[index] && line[index] != '\n')
	{
		free(path);
		return (NULL);
	}
	return (path);
}

/* Assigns the directional textures from the input line */
static int	assign_directional_textures(t_texinfo *textures, char *line,
		int index)
{
	if (line[index + 2] && ft_isprint(line[index + 2]))
		return (ERROR);
	if (line[index] == 'N' && line[index + 1] == 'O' && !textures->north)
		textures->north = extract_texture_path(line, index + 2);
	else if (line[index] == 'S' && line[index + 1] == 'O' && !textures->south)
		textures->south = extract_texture_path(line, index + 2);
	else if (line[index] == 'W' && line[index + 1] == 'E' && !textures->west)
		textures->west = extract_texture_path(line, index + 2);
	else if (line[index] == 'E' && line[index + 1] == 'A' && !textures->east)
		textures->east = extract_texture_path(line, index + 2);
	else
		return (ERROR);
	return (OK);
}

/* Processes the content of the line,
	ignoring whitespace and extracting information */
static int	process_line_content(t_info *game_info, char **file_lines,
		int line_index, int char_i)
{
	while (file_lines[line_index][char_i] == ' '
		|| file_lines[line_index][char_i] == '\t'
		|| file_lines[line_index][char_i] == '\n')
	{
		char_i++;
	}
	if (ft_isprint(file_lines[line_index][char_i])
		&& !ft_isdigit(file_lines[line_index][char_i]))
	{
		if (file_lines[line_index][char_i + 1]
			&& ft_isprint(file_lines[line_index][char_i + 1])
			&& !ft_isdigit(file_lines[line_index][char_i]))
		{
			if (assign_directional_textures(&game_info->texinfo,
					file_lines[line_index], char_i) == ERROR)
			{
				return (display_error_message(game_info->mapinfo.path,
						INVALID_TEXTURE, NOT_OK));
			}
			return (BREAK);
		}
		else
		{
			if (assign_color_textures(game_info, &game_info->texinfo,
					file_lines[line_index], char_i) == ERROR)
			{
				return (NOT_OK);
			}
			return (BREAK);
		}
	}
	else if (ft_isdigit(file_lines[line_index][char_i]))
	{
		if (generate_map(game_info, file_lines, line_index) == NOT_OK)
		{
			return (display_error_message(game_info->mapinfo.path, INVALID_MAP,
					NOT_OK));
		}
		return (OK);
	}
	return (CONTINUE);
}

/* Parses the data from the file lines */
int	retrieve_file_data(t_info *game_info, char **file_lines)
{
	int	line_index;
	int	char_i;
	int	process_result;

	line_index = 0;
	while (file_lines[line_index] != NULL)
	{
		char_i = 0;
		while (file_lines[line_index][char_i] != '\0')
		{
			process_result = process_line_content(game_info, file_lines,
					line_index, char_i);
			if (process_result == BREAK)
			{
				break ;
			}
			else if (process_result == NOT_OK)
			{
				return (NOT_OK);
			}
			else if (process_result == OK)
			{
				return (OK);
			}
			char_i++;
		}
		line_index++;
	}
	return (OK);
}
