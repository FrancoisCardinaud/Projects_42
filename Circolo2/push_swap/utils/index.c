/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:31 by francoiscar       #+#    #+#             */
/*   Updated: 2023/04/18 14:12:42 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
void	index_stack_elements(t_list **stack)
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

// Prints the Linked List
void	print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

void	three_op1(t_list **stack_a)
{
	rotate_a(stack_a);
	swap_a(stack_a);
	reverse_rotate_a(stack_a);
}

void	else_three(t_list **stack_a)
{
	swap_a(stack_a);
	reverse_rotate_a(stack_a);
}
