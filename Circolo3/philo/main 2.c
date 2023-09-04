/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:32:58 by fcardina          #+#    #+#             */
/*   Updated: 2023/06/07 17:04:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		check;

	if (argc != 5 && argc != 6)
	{
		write(1, "Wrong number of arguments\n", 26);
		return (1);
	}
	check = initialize(&data, argv);
	if (check)
	{
		write(1, "Error: One or more wrong arguments\n", 35);
		return (1);
	}
	if (proceed(&data))
	{
		write(1, "There was an error creating the threads\n", 40);
		return (1);
	}
	return (0);
}
