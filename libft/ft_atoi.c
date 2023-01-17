/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:31:33 by dstracke          #+#    #+#             */
/*   Updated: 2019/01/23 17:17:03 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;

	res = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\v' || *str == '\n' || \
					*str == '\f' || *str == '\t' || *str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : 1;
	while (*str && (*str >= '0' && *str <= '9'))
		res = res * 10 + *str++ - 48;
	if (res > 9223372036854775807)
		return (sign < 0) ? 0 : -1;
	return ((int)res * sign);
}
