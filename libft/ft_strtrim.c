/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:00:19 by dstracke          #+#    #+#             */
/*   Updated: 2019/01/30 12:26:28 by dstracke         ###   ########.fr       */
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
