/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:44:15 by fcardina          #+#    #+#             */
/*   Updated: 2023/01/23 16:33:41 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr)
			*(unsigned char *)ptr = 0;
	}
	else if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	else
	{
		ptr = malloc(count * size);
		if (ptr)
			ft_memset(ptr, 0, count * size);
	}
	return (ptr);
}
