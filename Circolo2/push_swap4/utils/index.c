/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:31 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/03/24 17:16:34 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the next minimum value node in the stack that hasn't been indexed yet
static t_list	*find_next_min_node(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		found_min;

	min = NULL;
	found_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!found_min || head->value < min->value))
			{
				min = head;
				found_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

// Assigns indexes to each node in the stack based on their value
void	assign_indexes_to_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = find_next_min_node(stack);
	while (head)
	{
		head->index = index++;
		head = find_next_min_node(stack);
	}
}
