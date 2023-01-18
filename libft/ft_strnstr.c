/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:43:27 by fcardina          #+#    #+#             */
/*   Updated: 2023/01/18 23:44:21 by fcardina         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*ned;

	i = 0;
	hay = (char *)haystack;
	ned = (char *)needle;
	if (!ned[i])
		return (&hay[i]);
	while (hay[i] && i < len)
	{
		j = 0;
		while (ned[j] && hay[i + j] == ned[j] && i + j < len)
			j++;
		if (!ned[j])
			return (&hay[i]);
		i++;
	}
	return (NULL);
}
