/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:43:27 by fcardina          #+#    #+#             */
/*   Updated: 2023/01/18 23:44:21 by fcardina         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	const char *t;

	if (!s)
		return (NULL);
	while (ft_simple_space(*s))
		s++;
	if (!s)
		return (NULL);
	t = s + ft_strlen(s) - 1;
	while (ft_simple_space(*t))
		t--;
	return (ft_strsub(s, 0, ft_strlen(s) - ft_strlen(t) + 1));
}
