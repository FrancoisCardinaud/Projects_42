/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:49:43 by dstracke          #+#    #+#             */
/*   Updated: 2019/01/30 12:02:13 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n = (-1) * n;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*buf;
	size_t	count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = count_word(n);
	if (!(buf = ft_strnew(count)))
		return (NULL);
	buf[count + 1] = '\0';
	if (n < 0)
	{
		n *= -1;
		buf[0] = '-';
	}
	while (n > 9)
	{
		buf[count - 1] = n % 10 + 48;
		n /= 10;
		count--;
	}
	buf[count - 1] = n + 48;
	return (buf);
}
