/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:43:27 by fcardina          #+#    #+#             */
/*   Updated: 2023/01/18 23:44:21 by fcardina         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(t = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		t[i] = s[start + i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
