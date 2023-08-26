/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:57:04 by fcardina          #+#    #+#             */
/*   Updated: 2023/08/26 01:57:53 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/sh.h"
#include "utils/libft/libft.h"

void	free_tcsh(t_csh *tcsh)
{
	if (tcsh->var.is_a_tty)
		ft_putendl("exit");
	ft_strdel(&tcsh->prompt.buff);
	ft_strdel(&tcsh->env.oldpwd);
	ft_arrdel(&tcsh->env.env);
}