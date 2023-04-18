/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:04:23 by francoiscar       #+#    #+#             */
/*   Updated: 2023/04/18 14:11:09 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_minimum(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	sort_three_numbers(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_minimum(stack_a, -1);
	next_min = get_minimum(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
		three_op1(stack_a);
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			swap_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	else
	{
		if (head->next->index == min)
			rotate_a(stack_a);
		else
			else_three(stack_a);
	}
}

static void	sort_four_numbers(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance_to_top(stack_a, get_minimum(stack_a, -1));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
		reverse_rotate_a(stack_a);
	if (is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_three_numbers(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance_to_top(stack_a, get_minimum(stack_a, -1));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (distance == 4)
		reverse_rotate_a(stack_a);
	if (is_sorted(stack_a))
		return ;
	push_b(stack_a, stack_b);
	sort_four_numbers(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_three_numbers(stack_a);
	else if (size == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (size == 5)
		sort_five_numbers(stack_a, stack_b);
}
