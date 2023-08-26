/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:52:08 by fcardina          #+#    #+#             */
/*   Updated: 2023/08/26 02:07:22 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/sh.h"

int	main(int ac, const char *av[], const char *env[])
{
	t_csh   tcsh;

	(void)ac;
	(void)av;
	if (init_tcsh(&tcsh, env) == 0)
	{
		while (!tcsh.var.exit)
		{
			loop_tcsh(&tcsh);
		}
	}
	free_tcsh(&tcsh);
	return (tcsh.var.return_value);
}
