/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:25 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/01 20:29:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

int	list_size(t_list *l)
{
	int	i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_list	*get_last(t_list *l)
{
	if (l == NULL)
		return (NULL);
	while (l->next)
	{
		l = l->next;
	}
	return (l);
}

int	list_contains_value(t_list *l, int value)
{
	while (l)
	{
		if (l->value == value)
			return (1);
		l = l->next;
	}
	return (0);
}

int	is_ordered(t_mem *m)
{
	int		prev;
	t_list	*l;

	if (m->b)
		return (0);
	if (!m->a)
		return (1);
	l = m->a;
	prev = l->value;
	while (l)
	{
		if (prev > l->value)
			return (0);
		prev = l->value;
		l = l->next;
	}
	return (1);
}
