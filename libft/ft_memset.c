/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:43:27 by fcardina          #+#    #+#             */
/*   Updated: 2023/01/18 23:44:21 by fcardina         ###   ########          */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char *)b;
	while (len)
		p[--len] = (unsigned char)c;
	return (b);
}
