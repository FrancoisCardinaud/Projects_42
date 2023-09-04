/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:28:36 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/11 17:41:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common/common.h"

void	rev_rotate_a(t_mem *mem)
{
	put_bottom_to_top(&(mem->a));
	if (mem->print)
		ft_putstr("rra");
}

void	rev_rotate_b(t_mem *mem)
{
	put_bottom_to_top(&(mem->b));
	if (mem->print)
		ft_putstr("rrb");
}

void	rev_rotate_b_a(t_mem *mem)
{
	put_bottom_to_top(&(mem->b));
	put_bottom_to_top(&(mem->a));
	if (mem->print)
		ft_putstr("rrr");
}

void	rotate_a(t_mem *mem)
{
	put_top_to_bottom(&(mem->a));
	if (mem->print)
		ft_putstr("ra");
}

void	rotate_b(t_mem *mem)
{
	put_top_to_bottom(&(mem->b));
	if (mem->print)
		ft_putstr("rb");
}
