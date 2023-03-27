/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:04:23 by francoiscar       #+#    #+#             */
/*   Updated: 2023/03/27 00:13:36 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	getMinimum(t_list **stack, int val)
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

static void	sortThreeNumbers(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = getMinimum(stack_a, -1);
	next_min = getMinimum(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		rotateA(stack_a);
		swapA(stack_a);
		reverseRotateA(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			swapA(stack_a);
		else
			reverseRotateA(stack_a);
	}
	else
	{
		if (head->next->index == min)
			rotateA(stack_a);
		else
		{
			swapA(stack_a);
			reverseRotateA(stack_a);
		}
	}
}

static void	sortFourNumbers(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (isSorted(stack_a))
		return ;
	distance = getDistance(stack_a, getMinimum(stack_a, -1));
	if (distance == 1)
		rotateA(stack_a);
	else if (distance == 2)
	{
		rotateA(stack_a);
		rotateA(stack_a);
	}
	else if (distance == 3)
		reverseRotateA(stack_a);
	if (isSorted(stack_a))
		return ;
	pushB(stack_a, stack_b);
	sortThreeNumbers(stack_a);
	pushA(stack_a, stack_b);
}

void	sortFiveNumbers(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = getDistance(stack_a, getMinimum(stack_a, -1));
	if (distance == 1)
		rotateA(stack_a);
	else if (distance == 2)
	{
		rotateA(stack_a);
		rotateA(stack_a);
	}
	else if (distance == 3)
	{
		reverseRotateA(stack_a);
		reverseRotateA(stack_a);
	}
	else if (distance == 4)
		reverseRotateA(stack_a);
	if (isSorted(stack_a))
		return ;
	pushB(stack_a, stack_b);
	sortFourNumbers(stack_a, stack_b);
	pushA(stack_a, stack_b);
}

void	simpleSort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (isSorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		swapA(stack_a);
	else if (size == 3)
		sortThreeNumbers(stack_a);
	else if (size == 4)
		sortFourNumbers(stack_a, stack_b);
	else if (size == 5)
		sortFiveNumbers(stack_a, stack_b);
}
