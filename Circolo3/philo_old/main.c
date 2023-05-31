/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:32:58 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/31 15:30:25 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	if (argc != 5 && argc != 6)
		return (print_error("Wrong amount of arguments"));
	ret = init(&data, argv);
	if (ret)
		return (error(ret));
	if (launcher(&data))
		return (print_error("There was an error creating the threads"));
	return (0);
}
