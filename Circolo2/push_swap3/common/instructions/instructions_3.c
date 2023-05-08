/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:28:42 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/02 14:01:50 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

void	rotate_b_a(t_mem *mem)
{
	put_top_to_bottom(&(mem->a));
	put_top_to_bottom(&(mem->b));
	if (mem->print)
		ft_putstr("rr");
}

void	ft_puterr(char *str)
{
	int		i;
	char	n;

	i = 0;
	while (str[i])
		i++;
	n = '\n';
	write(2, str, i);
	write(2, &n, 1);
}
