/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:51:14 by aperez-b          #+#    #+#             */
/*   Updated: 2023/05/02 15:41:37 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	st_swap_ss(t_list **a, t_list **b)
{
	st_swap_ab(a, 0);
	st_swap_ab(b, 0);
	ft_putstr_fd("ss\n", 1);
	return (1);
}

int	st_rotate_rr(t_list **a, t_list **b)
{
	if (!st_rotate_ab(a, 0))
		return (0);
	if (!st_rotate_ab(b, 0))
		return (0);
	ft_putstr_fd("rr\n", 1);
	return (1);
}

int	st_rrotate_rrr(t_list **a, t_list **b)
{
	if (!st_rrotate_ab(a, 0))
		return (0);
	if (!st_rrotate_ab(b, 0))
		return (0);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
