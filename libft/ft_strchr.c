/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:17:40 by dstracke          #+#    #+#             */
/*   Updated: 2019/01/23 20:39:02 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!*s && !s)
		return (NULL);
	if (*s == (char)c)
		return ((char*)s);
	while (*s++)
	{
		if (*s == (char)c)
			return ((char*)s);
	}
	return (NULL);
}
