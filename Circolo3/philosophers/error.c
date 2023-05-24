/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:31:56 by gsmets            #+#    #+#             */
/*   Updated: 2023/05/24 14:23:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error(int err)
{
	if (err == 1)
		return (print_error("At least one wrong argument"));
	if (err == 2)
		return (print_error("Fatal error when intializing semaphores"));
	return (1);
}
