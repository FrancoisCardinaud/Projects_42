/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:45:50 by fcardina          #+#    #+#             */
/*   Updated: 2023/04/20 15:55:22 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burningship_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 220;
	data->x1 = -1.7;
	data->y1 = -2;
	data->color = 265;
}

void	burningship_compute(t_fractol *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
		&& data->it < data->it_max)
	{
		data->tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_i;
		data->z_r = data->tmp;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0xffffff);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*burningship(void *tab)
{
	int			i;
	t_fractol	*data;

	data = (t_fractol *)tab;
	data->x = 0;
	i = data->y;
	while (data->x < WIDTH)
	{
		data->y = i;
		while (data->y < data->y_max)
		{
			burningship_compute(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	burningship_pthread(t_fractol *data)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, burningship, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
