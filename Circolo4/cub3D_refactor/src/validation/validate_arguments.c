/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:22:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 17:32:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
**	Checks whether the argument is a correct .cub extension,
**	checks that it exists and isn't a directory instead of a file.
*/

int	is_whitespace(char character)
{
	if (character != ' ' && character != '\t' && character != '\r'
		&& character != '\n' && character != '\v' && character != '\f')
		return (NOT_OK);
	else
		return (OK);
}

/* Checks if the file path points to a directory */
static bool	check_is_directory(char *file_path)
{
	int		file_descriptor;
	bool	result;

	result = false;
	file_descriptor = open(file_path, O_DIRECTORY);
	if (file_descriptor >= 0)
	{
		close(file_descriptor);
		result = true;
	}
	return (result);
}

/* Validates if the file path has a .cub extension */
static bool	validate_cub_file(char *file_path)
{
	size_t	path_length;

	path_length = ft_strlen(file_path);
	if ((file_path[path_length - 3] != 'c' || file_path[path_length - 2] != 'u'
			|| file_path[path_length - 1] != 'b' || file_path[path_length
				- 4] != '.'))
		return (false);
	return (true);
}

/* Validates if the file path has a .xpm extension */
static bool	validate_xpm_file(char *file_path)
{
	size_t	path_length;

	path_length = ft_strlen(file_path);
	if ((file_path[path_length - 3] != 'x' || file_path[path_length - 2] != 'p'
			|| file_path[path_length - 1] != 'm' || file_path[path_length
				- 4] != '.'))
		return (false);
	return (true);
}

/* Verifies the validity of the given file path */
int	verify_file(char *file_path, bool is_cub)
{
	int	file_descriptor;

	if (check_is_directory(file_path))
		return (display_error_message(file_path, FILE_IS_DIR, NOT_OK));
	file_descriptor = open(file_path, O_RDONLY);
	if (file_descriptor == -1)
		return (display_error_message(file_path, strerror(errno), NOT_OK));
	close(file_descriptor);
	if (is_cub && !validate_cub_file(file_path))
		return (display_error_message(file_path, FILE_NOT_CUB, NOT_OK));
	if (!is_cub && !validate_xpm_file(file_path))
		return (display_error_message(file_path, FILE_NOT_XPM, NOT_OK));
	return (OK);
}
