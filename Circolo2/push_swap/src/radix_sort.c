/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:43:47 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/03/02 21:43:49 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_maxbits_lst(t_lst **stack)
{
	t_lst	*lst;
	int		max;
	int		max_b;

	lst = *stack;
	max = lst->index;
	max_b = 0;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}

int	lst_size(t_lst *stack)
{
	int		i;
	t_lst	*lst;

	lst = stack;
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	radix_sort(t_lst **a_stack, t_lst **b_stack)
{
	t_lst	*lst;
	int		i;
	int		j;
	int		size;
	int		max_b;

	lst = *a_stack;
	size = lst_size(*a_stack);
	max_b = get_maxbits_lst(a_stack);
	i = -1;
	while (++i < max_b)
	{
		j = -1;
		while (++j < size)
		{
			lst = *a_stack;
			if (((lst->index >> i) & 1) == 0)
				do_pb(a_stack, b_stack);
			else
				do_ra(a_stack);
		}
		while (lst_size(*b_stack) != 0)
			do_pa(a_stack, b_stack);
	}
}
