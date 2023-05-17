/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:20:40 by gsmets            #+#    #+#             */
/*   Updated: 2023/05/17 18:50:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (print_error("Wrong amount of arguments"));
	ret = init(&rules, argv);
	if (ret)
		return (error(ret));
	if (launcher(&rules))
		return (print_error("There was an error creating the threads"));
	return (0);
}
