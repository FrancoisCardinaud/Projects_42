/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:59:26 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 18:21:24 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot_pthread(data);
	else if (data->fract == 1)
		julia_pthread(data);
	else if (data->fract == 2)
		burningship_pthread(data);
	if (data->show_text)
		put_text(data);
}

void	fract_init(t_fractol *data)
{
	if (data->fract == 0)
		mandelbrot_init(data);
	else if (data->fract == 1)
		julia_init(data);
	else if (data->fract == 2)
		burningship_init(data);
	fract_calc(data);
}

void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
}

int	fract_comp(char **av, t_fractol *data)
{
	if (ft_strcmp(av[1], "M") == 0)
		data->fract = 0;
	else if (ft_strcmp(av[1], "J") == 0)
		data->fract = 1;
	else if (ft_strcmp(av[1], "B") == 0)
		data->fract = 2;
	else
	{
		ft_putstr("Usage:\n");
		ft_putendl("./fractol [M = mandelbrot,  J = julia, B = burningship]");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	*data;

	data = (t_fractol *)malloc(sizeof(t_fractol));
	if (!data)
		return (-1);
	if (ac == 2)
	{
		mlx_win_init(data);
		if ((fract_comp(av, data)) == 0)
			return (0);
		fract_init(data);
		mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
		mlx_hook(data->win, 17, 0L, ft_close, data);
		mlx_key_hook(data->win, key_hook, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop(data->mlx);
	}
	else
	{
		ft_putstr("Usage:\n");
		ft_putendl("./fractol [M = mandelbrot,  J = julia, B = burningship]");
	}
	return (0);
}
