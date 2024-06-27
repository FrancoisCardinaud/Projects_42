/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 03:21:44 by fcardina          #+#    #+#             */
/*   Updated: 2024/06/22 16:31:56 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Displays an error message with an optional detail and code */
int	display_error_message(char *error_detail, char *display_error_message, int error_code)
{
	ft_putstr_fd(RED "cub3D: Error", 2);
	if (error_detail)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(error_detail, 2);
	}
	if (display_error_message)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(display_error_message, 2);
	}
	ft_putstr_fd("\n" RESET, 2);
	return (error_code);
}

/* Displays an error message with an integer detail and code */
int	display_error_with_value(int error_detail, char *display_error_message, int error_code)
{
	ft_putstr_fd(RED "cub3D: Error: ", 2);
	ft_putnbr_fd(error_detail, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(display_error_message, 2);
	ft_putstr_fd("\n" RESET, 2);
	return (error_code);
}
