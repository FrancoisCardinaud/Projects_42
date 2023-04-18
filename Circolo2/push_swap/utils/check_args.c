/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:14:56 by francoiscar       #+#    #+#             */
/*   Updated: 2023/04/18 14:12:12 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	has_number(int num, char **args, int startIdx)
{
	startIdx++;
	while (args[startIdx])
	{
		if (ft_atoi(args[startIdx]) == num)
		{
			return (1);
		}
		startIdx++;
	}
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnbr(args[i]))
			report_error("Invalid input");
		if (has_number(tmp, args, i))
			report_error("Duplicate input");
		if (tmp < -2147483648 || tmp > 2147483647)
			report_error("Input out of range");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
