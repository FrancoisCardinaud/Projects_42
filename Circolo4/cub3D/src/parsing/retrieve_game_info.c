/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_g_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/15 22:11:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* Finds the length of the longest line in the map file */
size_t	find_max_length(t_mapinfo *map_info, int li)
{
	size_t	current_length;
	size_t	max_length;

	max_length = 0;
	while (map_info->file[li])
	{
		current_length = ft_strlen(map_info->file[li]);
		if (current_length > max_length)
			max_length = current_length;
		li++;
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
static int	assign_dir_text(t_texture_info *textures, char *line, int index)
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
static int	process_line_content(t_info *g_info, char **l, int li, int c)
{
	while (l[li][c] == ' ' || l[li][c] == '\t' || l[li][c] == '\n')
		c++;
	if (ft_isprint(l[li][c]) && !ft_isdigit(l[li][c]))
	{
		if (l[li][c + 1] && ft_isprint(l[li][c + 1]) && !ft_isdigit(l[li][c]))
		{
			if (assign_dir_text(&g_info->texinfo, l[li], c) == ERROR)
				return (disp_err_msg(g_info->mapinfo.path, INV_TEXTURE,
						NOT_OK));
			return (BREAK);
		}
		else
		{
			if (assign_col_tex(g_info, &g_info->texinfo, l[li], c) == ERROR)
				return (NOT_OK);
			return (BREAK);
		}
	}
	else if (ft_isdigit(l[li][c]))
	{
		if (generate_map(g_info, l, li) == NOT_OK)
			return (disp_err_msg(g_info->mapinfo.path, INV_MAP, NOT_OK));
		return (OK);
	}
	return (CONTINUE);
}

/* Parses the data from the file lines */
int	retrieve_file_data(t_info *g_info, char **l)
{
	int	li;
	int	c;
	int	process_result;

	li = 0;
	while (l[li] != NULL)
	{
		c = 0;
		while (l[li][c] != '\0')
		{
			process_result = process_line_content(g_info, l, li, c);
			if (process_result == BREAK)
				break ;
			else if (process_result == NOT_OK)
				return (NOT_OK);
			else if (process_result == OK)
				return (OK);
			c++;
		}
		li++;
	}
	return (OK);
}
