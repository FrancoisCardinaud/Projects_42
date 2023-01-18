/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:43:27 by fcardina          #+#    #+#             */
/*   Updated: 2023/01/18 23:44:21 by fcardina         ###   ########          */
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
