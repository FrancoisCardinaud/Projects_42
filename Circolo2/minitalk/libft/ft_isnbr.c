/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:55:24 by francoiscar       #+#    #+#             */
/*   Updated: 2024/04/17 03:21:45 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnbr(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0 && str[0] != '-')
			return (0);
		str++;
	}
	return (1);
}
