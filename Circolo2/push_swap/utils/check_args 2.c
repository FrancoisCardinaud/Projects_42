/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:14:56 by fcardina          #+#    #+#             */
/*   Updated: 2023/04/18 16:25:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>
#include <unistd.h>

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

int	number_limit(char *n)
{
	if ((ft_atol(n) > INT_MAX) || (ft_atol(n) < -INT_MAX))
	{
		return (1);
	}
	else
		return (0);
}

void	ft_check_args(int argc, char **argv)
{
	int			i;
	long long	tmp;
	char		**args;
	int			*numbers_in_stack;

	i = 0;
	numbers_in_stack = (int *)malloc(2 * sizeof(int) + 2);
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
			report_error("Error");
		if (has_number(tmp, args, i))
			report_error("Error");
		if (number_limit(args[i]))
			report_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
