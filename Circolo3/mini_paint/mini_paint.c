/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:28:31 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/16 18:33:42 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

void	ft_allocate_print(t_dflt *dflt)
{
	int	y;

	dflt->paint = calloc(dflt->h + 1, 8);
	y = 0;
	while (y < dflt->h)
	{
		dflt->paint[y] = calloc(dflt->w + 1, 1);
		memset(dflt->paint[y], dflt->c, dflt->w);
		y++;
	}
}

float	distance(t_paint *paint, int x, int y)
{
	float	f;

	f = sqrt(powf(paint->x - x, 2) + powf(paint->y - y, 2));
	return (f);
}

void	ft_update_paint(t_dflt *dflt, t_paint *paint)
{
	int	x;
	int	y;

	if ((int)paint->r <= 0)
		return ;
	y = 0;
	while (dflt->paint[y])
	{
		x = 0;
		while (dflt->paint[y][x])
		{
			if (paint->type == 67 && distance(paint, x, y) <= paint->r)
				dflt->paint[y][x] = paint->c;
			else if (paint->type == 99)
				if (distance(paint, x, y)  <= paint->r && distance(paint, x, y) + 1 >= paint->r)
					dflt->paint[y][x] = paint->c;
			x++;
		}
		y++;
	}
}

void	ft_print_and_free(t_dflt *dflt)
{
	int	y;

	y = 0;
	while (dflt->paint[y])
	{
		write(1, dflt->paint[y], dflt->w);
		free(dflt->paint[y]);
		write(1, "\n", 1);
		y++;
	}
	free(dflt->paint);
}

int	main(int ac, char **av)
{
	t_dflt	dflt;
	t_paint	paint;
	FILE	*fd;
	int		args;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16); 
		return (1);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	args = fscanf(fd, "%d %d %c \n", &dflt.w, &dflt.h, &dflt.c);
	if (args < 3 || dflt.w <= 0 || dflt.w > 300 || dflt.h <=0 || dflt.h > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	ft_allocate_print(&dflt);
	while (1)
	{
		args = fscanf(fd, "%c %f %f %f %c \n", &paint.type, \
				&paint.x, &paint.y, &paint.r, &paint.c);
		if (args == -1)
			break;
		if ((args > -1 && args < 5) || (paint.type != 99 && paint.type != 67) || paint.r <= 0)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		ft_update_paint(&dflt, &paint);
	}
	ft_print_and_free(&dflt);
	return (0);
}