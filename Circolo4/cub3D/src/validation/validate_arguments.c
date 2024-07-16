/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/16 18:07:48 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
**	Checks whether the argument is a correct .cub extension,
**	checks that it exists and isn't a directory instead of a file.
*/

int	check_is_space(char character)
{
	if (character != ' ' && character != '\t' && character != '\r'
		&& character != '\n' && character != '\v' && character != '\f')
		return (NOT_OK);
	else
		return (OK);
}

/* Validates if the file path has a .cub extension */
static bool	check_cub(char *f_p)
{
	size_t	p_l;

	p_l = ft_strlen(f_p);
	if ((f_p[p_l - 3] != 'c' || f_p[p_l - 2] != 'u' || f_p[p_l - 1] != 'b'
			|| f_p[p_l - 4] != '.'))
		return (false);
	return (true);
}

/* Checks if the file path points to a directory */
static bool	check_is_directory(char *file_path)
{
	int	file_descriptor;

	file_descriptor = open(file_path, O_DIRECTORY);
	if (file_descriptor >= 0)
	{
		close(file_descriptor);
		return (true);
	}
	return (false);
}

/* Validates if the file path has a .xpm extension */
static bool	check_xpm(char *file_path)
{
	size_t	p_l;

	p_l = ft_strlen(file_path);
	return (p_l >= 4 && file_path[p_l - 4] == '.' && file_path[p_l - 3] == 'x'
		&& file_path[p_l - 2] == 'p' && file_path[p_l - 1] == 'm');
}

/* Verifies the validity of the given file path */
int	validate_file(char *file_path, bool is_cub)
{
	int	file_descriptor;

	if (check_is_directory(file_path))
		return (disp_err_msg(file_path, IS_NOT_FILE, NOT_OK));
	file_descriptor = open(file_path, O_RDONLY);
	if (file_descriptor == -1)
		return (disp_err_msg(file_path, strerror(errno), NOT_OK));
	close(file_descriptor);
	if (is_cub && !check_cub(file_path))
		return (disp_err_msg(file_path, INV_CUB_FILE, NOT_OK));
	if (!is_cub && !check_xpm(file_path))
		return (disp_err_msg(file_path, INV_TEXTURE_FILE, NOT_OK));
	return (OK);
}
