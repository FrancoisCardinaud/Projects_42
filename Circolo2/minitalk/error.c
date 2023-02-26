/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:04:50 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/02/21 23:05:04 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(char *str_error)
{
	write(2, str_error, ft_strlen(str_error));
	exit(1);
}
