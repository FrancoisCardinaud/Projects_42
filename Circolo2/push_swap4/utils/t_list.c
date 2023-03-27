/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:31 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/03/24 17:17:42 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a new node and return a pointer to it
t_list	*create_node(int value)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

// Add a node to the beginning of the list, making it the new head
void	add_to_front(t_list **stack, t_list *node)
{
	node->next = *stack;
	*stack = node;
}

// Return the last node in the list
t_list	*get_last_node(t_list *head)
{
	t_list	*node;

	node = head;
	while (node->next)
		node = node->next;
	return (node);
}

// Add a node to the end of the list
void	add_to_end(t_list **stack, t_list *node)
{
	t_list	*last;

	if (*stack)
	{
		last = get_last_node(*stack);
		last->next = node;
		node->next = NULL;
	}
	else
	{
		*stack = node;
		(*stack)->next = NULL;
	}
}

// Return the size of the list
int	get_list_size(t_list *head)
{
	size_t	size;
	t_list	*node;

	node = head;
	size = 0;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}

// Print the list
void	print_list(t_list *head)
{
	t_list	*node;

	node = head;
	while (node != NULL)
	{
		ft_putnbr_fd(node->value, 1);
		ft_putendl_fd("", 1);
		node = node->next;
	}
}
