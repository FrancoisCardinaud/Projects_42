/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main 2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:16:15 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:21:24 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_t *t)
{
	/*int	i;
	int	j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = 599;
		while (++i < 1000)
		{
			t->index = (j * 1000 * 4) + (i * 4);
			t->ch[t->index] = 189;
			t->ch[t->index + 1] = 87;
			t->ch[t->index + 2] = 54;
			t->ch[t->index + 3] = 0;
		}
	}*/
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	//string1_put(t);
	//string_put(t);
}
/*
void	string_put(t_t *t)
{
	mlx_string_put(t->ptr, t->win, 650, 70, 0xf7b079,
		"       Scroll UP | Scroll DOWN         ");
	mlx_string_put(t->ptr, t->win, 650, 110, 0xFFFFFF,
		"-------------MOVE------------");
	mlx_string_put(t->ptr, t->win, 650, 140, 0xf7b079,
		"        Arrow UP | Arrow DOWN    ");
	mlx_string_put(t->ptr, t->win, 650, 180, 0xf7b079,
		"     Arrow RIGHT | Arrow LEFT ");
	mlx_string_put(t->ptr, t->win, 650, 240, 0xFFFFFF,
		"--------CHANGE FRACTAL-------");
	mlx_string_put(t->ptr, t->win, 650, 280, 0xf7b079,
		"      Mandelbrot | PRESS 3 ");
	mlx_string_put(t->ptr, t->win, 650, 310, 0xf7b079,
		"     BurningShip | PRESS 2 ");
	mlx_string_put(t->ptr, t->win, 650, 340, 0xf7b079,
		"           Julia | PRESS 1 ");
	mlx_string_put(t->ptr, t->win, 650, 380, 0xFFFFFF,
		"--------CHANGE COLOR-------");
	mlx_string_put(t->ptr, t->win, 650, 410, 0xf7b079,
		"           BUTTON (enter) ");
	mlx_string_put(t->ptr, t->win, 650, 440, 0xFFFFFF,
		"--------RESTART FRACTAL-------");
	mlx_string_put(t->ptr, t->win, 650, 470, 0xf7b079,
		"           BUTTON (0) ");
}*/

void	init(t_t *t, char *str)
{
	t->start_x = -2;
	t->end_x = 2;
	t->start_y = -2;
	t->end_y = 2;
	t->x_o = -0.4;
	t->y_o = 0.6;
	t->zoom = 0;
	t->stop = 0;
	t->max = 40;
	t->color = 20;
	t->name = str;
}

void	check_ar(t_t *t)
{
	if (ft_strcmp(t->name, "Mandelbrot") == 0)
		mandelbrot(t);
	else if (ft_strcmp(t->name, "Julia") == 0)
		julia(t);
	else
	{
		write(1, "How to use: ./fractol <name>", 28);
		write(1, "\tMandelbrot\tJulia\n", 18);
	}
}

int	main(int ac, char *av[])
{
	t_t	t;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "Julia") == 0)
		{
			t.ptr = mlx_init();
			t.win = mlx_new_window(t.ptr, 600, 600, "Fractol");
			t.image = mlx_new_image(t.ptr, WIDTH + 400, HEIGHT);
			t.ch = (unsigned char *)mlx_get_data_addr(t.image, &t.bpp,
					&t.size_l, &t.endian);
		}
		init(&t, av[1]);
		check_ar(&t);
	}
	else
	{
		write(1, "How to use: ./fractol <name>", 28);
		write(1, "\tMandelbrot\tJulia\n", 18);
	}
	return (0);
}
