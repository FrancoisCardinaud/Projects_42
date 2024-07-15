/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean 2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:12:29 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 17:26:28 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/common/common.h"

void	clear_all(t_mem *mem)
{
	ft_free_list(&(mem->a));
	ft_free_list(&(mem->b));
}

void	exit_error(t_mem *mem)
{
	ft_puterr("Error");
	clear_all(mem);
	exit(EXIT_FAIL);
}
