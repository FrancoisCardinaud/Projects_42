/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/12 17:29:49 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Extracts the texture path from the input line */
static char	*extract_texture_path(char *in_line, int char_i)
{
	int		len;
	int		i;
	char	*texture_path;

	while (in_line[char_i] && (in_line[char_i] == ' '
			|| in_line[char_i] == '\t'))
		char_i++;
	len = char_i;
	while (in_line[len] && (in_line[len] != ' ' && in_line[len] != '\t'))
		len++;
	texture_path = malloc(sizeof(char) * (len - char_i + 1));
	if (!texture_path)
		return (NULL);
	i = 0;
	while (in_line[char_i] && (in_line[char_i] != ' ' && in_line[char_i] != '\t'
			&& in_line[char_i] != '\n'))
		texture_path[i++] = in_line[char_i++];
	texture_path[i] = '\0';
	while (in_line[char_i] && (in_line[char_i] == ' '
			|| in_line[char_i] == '\t'))
		char_i++;
	if (in_line[char_i] && in_line[char_i] != '\n')
	{
		free(texture_path);
		texture_path = NULL;
	}
	return (texture_path);
}

/* Assigns the directional textures from the input line */
static int	assign_directional_textures(t_texinfo *texture_info, char *in_line,
		int char_i)
{
	if (in_line[char_i + 2] && ft_isprint(in_line[char_i + 2]))
		return (ERR);
	if (in_line[char_i] == 'N' && in_line[char_i + 1] == 'O'
		&& !(texture_info->north))
		texture_info->north = extract_texture_path(in_line, char_i + 2);
	else if (in_line[char_i] == 'S' && in_line[char_i + 1] == 'O'
		&& !(texture_info->south))
		texture_info->south = extract_texture_path(in_line, char_i + 2);
	else if (in_line[char_i] == 'W' && in_line[char_i + 1] == 'E'
		&& !(texture_info->west))
		texture_info->west = extract_texture_path(in_line, char_i + 2);
	else if (in_line[char_i] == 'E' && in_line[char_i + 1] == 'A'
		&& !(texture_info->east))
		texture_info->east = extract_texture_path(in_line, char_i + 2);
	else
		return (ERR);
	return (SUCCESS);
}

/* Processes the content of the line,
	ignoring whitespace and extracting information */
static int	process_line_content(t_data *game_data, char **file_lines,
		int line_index, int char_i)
{
	while (file_lines[line_index][char_i] == ' '
		|| file_lines[line_index][char_i] == '\t'
		|| file_lines[line_index][char_i] == '\n')
		char_i++;
	if (ft_isprint(file_lines[line_index][char_i])
		&& !ft_isdigit(file_lines[line_index][char_i]))
	{
		if (file_lines[line_index][char_i + 1]
			&& ft_isprint(file_lines[line_index][char_i + 1])
			&& !ft_isdigit(file_lines[line_index][char_i]))
		{
			if (assign_directional_textures(&game_data->texinfo,
					file_lines[line_index], char_i) == ERR)
				return (display_error_message(game_data->mapinfo.path,
						ERR_TEX_INVALID, FAILURE));
			return (BREAK);
		}
		else
		{
			if (assign_color_textures(game_data, &game_data->texinfo,
					file_lines[line_index], char_i) == ERR)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(file_lines[line_index][char_i]))
	{
		if (generate_map(game_data, file_lines, line_index) == FAILURE)
			return (display_error_message(game_data->mapinfo.path,
					ERR_INVALID_MAP, FAILURE));
		return (SUCCESS);
	}
	return (CONTINUE);
}

/* Parses the data from the file lines */
int	retrieve_file_data(t_data *game_data, char **file_lines)
{
	int	line_index;
	int	char_i;
	int	process_result;

	line_index = 0;
	while (file_lines[line_index])
	{
		char_i = 0;
		while (file_lines[line_index][char_i])
		{
			process_result = process_line_content(game_data, file_lines,
					line_index, char_i);
			if (process_result == BREAK)
				break ;
			else if (process_result == FAILURE)
				return (FAILURE);
			else if (process_result == SUCCESS)
				return (SUCCESS);
			char_i++;
		}
		line_index++;
	}
	return (SUCCESS);
}
