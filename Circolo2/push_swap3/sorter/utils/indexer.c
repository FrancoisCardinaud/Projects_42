/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:07:41 by ttranche          #+#    #+#             */
/*   Updated: 2023/05/11 17:43:39 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sorter/sorter.h"

void	tag_list(t_list *start, t_mem *mem)
{
	int	i;

	i = 0;
	while (start)
	{
		start->index = i++;
		start = start->next_sort;
	}
	mem->max = i;
}
