/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/22 16:32:49 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Extracts the texture path from the input line */
static char	*extract_texture_path(char *input_line, int char_index)
{
	int		len;
	int		i;
	char	*texture_path;

	while (input_line[char_index] && (input_line[char_index] == ' ' || input_line[char_index] == '\t'))
		char_index++;
	len = char_index;
	while (input_line[len] && (input_line[len] != ' ' && input_line[len] != '\t'))
		len++;
	texture_path = malloc(sizeof(char) * (len - char_index + 1));
	if (!texture_path)
		return (NULL);
	i = 0;
	while (input_line[char_index] && (input_line[char_index] != ' ' && input_line[char_index] != '\t' && input_line[char_index] != '\n'))
		texture_path[i++] = input_line[char_index++];
	texture_path[i] = '\0';
	while (input_line[char_index] && (input_line[char_index] == ' ' || input_line[char_index] == '\t'))
		char_index++;
	if (input_line[char_index] && input_line[char_index] != '\n')
	{
		free(texture_path);
		texture_path = NULL;
	}
	return (texture_path);
}

/* Assigns the directional textures from the input line */
static int	assign_directional_textures(t_texinfo *texture_info, char *input_line, int char_index)
{
	if (input_line[char_index + 2] && ft_isprint(input_line[char_index + 2]))
		return (ERR);
	if (input_line[char_index] == 'N' && input_line[char_index + 1] == 'O' && !(texture_info->north))
		texture_info->north = extract_texture_path(input_line, char_index + 2);
	else if (input_line[char_index] == 'S' && input_line[char_index + 1] == 'O' && !(texture_info->south))
		texture_info->south = extract_texture_path(input_line, char_index + 2);
	else if (input_line[char_index] == 'W' && input_line[char_index + 1] == 'E' && !(texture_info->west))
		texture_info->west = extract_texture_path(input_line, char_index + 2);
	else if (input_line[char_index] == 'E' && input_line[char_index + 1] == 'A' && !(texture_info->east))
		texture_info->east = extract_texture_path(input_line, char_index + 2);
	else
		return (ERR);
	return (SUCCESS);
}

/* Processes the content of the line, ignoring whitespace and extracting information */
static int	process_line_content(t_data *game_data, char **file_lines, int line_index, int char_index)
{
	while (file_lines[line_index][char_index] == ' ' || file_lines[line_index][char_index] == '\t' || file_lines[line_index][char_index] == '\n')
		char_index++;
	if (ft_isprint(file_lines[line_index][char_index]) && !ft_isdigit(file_lines[line_index][char_index]))
	{
		if (file_lines[line_index][char_index + 1] && ft_isprint(file_lines[line_index][char_index + 1])
			&& !ft_isdigit(file_lines[line_index][char_index]))
		{
			if (assign_directional_textures(&game_data->texinfo, file_lines[line_index], char_index) == ERR)
				return (display_error_message(game_data->mapinfo.path, ERR_TEX_INVALID, FAILURE));
			return (BREAK);
		}	
		else
		{
			if (assign_color_textures(game_data, &game_data->texinfo, file_lines[line_index], char_index) == ERR)
				return (FAILURE);
			return (BREAK);
		}	
	}
	else if (ft_isdigit(file_lines[line_index][char_index]))
	{
		if (generate_map(game_data, file_lines, line_index) == FAILURE)
			return (display_error_message(game_data->mapinfo.path, ERR_INVALID_MAP, FAILURE));
		return (SUCCESS);
	}
	return (CONTINUE);
}

/* Parses the data from the file lines */
int	retrieve_file_data(t_data *game_data, char **file_lines)
{
	int	line_index;
	int	char_index;
	int	process_result;

	line_index = 0;
	while (file_lines[line_index])
	{
		char_index = 0;
		while (file_lines[line_index][char_index])
		{
			process_result = process_line_content(game_data, file_lines, line_index, char_index);
			if (process_result == BREAK)
				break ;
			else if (process_result == FAILURE)
				return (FAILURE);
			else if (process_result == SUCCESS)
				return (SUCCESS);
			char_index++;
		}
		line_index++;
	}
	return (SUCCESS);
}
