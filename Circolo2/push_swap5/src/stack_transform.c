/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:30:04 by aperez-b          #+#    #+#             */
/*   Updated: 2023/05/02 15:41:39 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	st_swap_ab(t_list **stack, char c)
{
	void	*temp;
	t_list	*head;

	head = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		temp = head->content;
		head->content = head->next->content;
		head->next->content = temp;
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		if (c == 'b')
			ft_putstr_fd("sb\n", 1);
		return (1);
	}
	return (0);
}

int	st_push_ab(t_list **a, t_list **b, char c)
{
	void	*temp;

	if (ft_lstsize(*b))
	{
		temp = st_pop(b);
		st_push(a, temp, sizeof(int));
		free(temp);
		if (c == 'a')
			ft_putstr_fd("pa\n", 1);
		if (c == 'b')
			ft_putstr_fd("pb\n", 1);
		return (1);
	}
	return (0);
}

int	st_rotate_ab(t_list **stack, char c)
{
	void	*content;

	if (ft_lstsize(*stack) > 1)
	{
		content = st_pop(stack);
		ft_lstadd_back(stack, ft_lstnew(content));
		if (c == 'a')
			ft_putstr_fd("ra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rb\n", 1);
		return (1);
	}
	return (0);
}

int	st_rrotate_ab(t_list **stack, char c)
{
	void	*content;
	t_list	*last_a;
	t_list	*prev;

	if (ft_lstsize(*stack) > 1)
	{
		last_a = st_get_at(*stack, ft_lstsize(*stack) - 1);
		prev = st_get_at(*stack, ft_lstsize(*stack) - 2);
		content = last_a->content;
		st_push(stack, content, sizeof(int));
		ft_lstdelone(last_a, free);
		prev->next = NULL;
		if (c == 'a')
			ft_putstr_fd("rra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	return (0);
}
