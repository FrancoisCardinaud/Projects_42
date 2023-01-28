/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:12:56 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/01/23 09:17:01 by dfiliagg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*count;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	count = lst;
	while (count->next != 0)
	{
		count = count->next;
		i++;
	}
	return (i);
}
