/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoiscardinaud <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:45:17 by francoiscardi     #+#    #+#             */
/*   Updated: 2023/03/02 21:45:19 by francoiscardi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include "printf/libft/libft.h"
# include "printf/ft_printf/libftprintf.h"

typedef struct s_lst
{
	int				content;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

int		is_sorted(t_lst **stack);
void	simple_sort(t_lst **a_stack, t_lst **b_stack);
int		is_sorted(t_lst **stack);
int		is_order(t_lst **stack, int size);
void	reset_index(t_lst **stack);
void	rotate_to_min(t_lst **stack, int size);
void	ps_index(t_lst **stack);
int		lst_size(t_lst *lst);
void	radix_sort(t_lst **a_stack, t_lst **b_stack);
void	lst_addfront(t_lst **stack, t_lst *news);
void	lst_addback(t_lst **stack, t_lst *news);
t_lst	*lst_new(int content);
t_lst	*lst_last(t_lst *stack);
void	do_sa(t_lst **stack);
void	do_sb(t_lst **stack);
void	do_ss(t_lst **a_stack, t_lst **b_stack);
void	do_pa(t_lst **a_stack, t_lst **b_stack);
void	do_pb(t_lst **a_stack, t_lst **b_stack);
void	rotate(t_lst **stack);
void	do_ra(t_lst **stack);
void	do_rb(t_lst **stack);
void	do_rr(t_lst **a_stack, t_lst **b_stack);
void	reverse(t_lst **stack);
void	do_rra(t_lst **stack);
void	do_rrb(t_lst **stack);
void	do_rrr(t_lst **a_stack, t_lst **b_stack);

#endif
