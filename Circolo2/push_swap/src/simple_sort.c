/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:54:47 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/03/06 14:54:50 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_tree(t_lst **stack)
{
	while (is_sorted(stack) != 1)
	{
		if (((*stack)->index > (*stack)->next->index)
			&& ((*stack)->index < (*stack)->next->next->index))
			do_sa(stack);
		else if (((*stack)->index > ((*stack)->next->index))
			&& ((*stack)->index > (*stack)->next->next->index))
			do_ra(stack);
		else
			do_rra(stack);
	}
}

static void	sort_four(t_lst **a_stack, t_lst **b_stack)
{
	if (is_order(a_stack, 4) == 1)
		return ;
	rotate_to_min(a_stack, 4);
	do_pb(a_stack, b_stack);
	reset_index(a_stack);
	sort_tree(a_stack);
	do_pa(a_stack, b_stack);
}

void	simple_sort(t_lst **a_stack, t_lst **b_stack)
{
	int	size;

	size = lst_size(*a_stack);
	if (size == 3)
		sort_tree(a_stack);
	else if (size == 4)
		sort_four(a_stack, b_stack);
	else
	{
		if (is_order(a_stack, 5) == 1)
			return ;
		rotate_to_min(a_stack, 5);
		do_pb(a_stack, b_stack);
		reset_index(a_stack);
		sort_four(a_stack, b_stack);
		do_pa(a_stack, b_stack);
	}
}
