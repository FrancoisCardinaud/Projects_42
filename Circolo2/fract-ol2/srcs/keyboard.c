/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:00:26 by fcardina          #+#    #+#             */
/*   Updated: 2023/04/18 14:26:40 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook2(int keycode, t_fractol *data)
{
	if (keycode == 19)
		data->color = 2050;
	else if (keycode == 20)
		data->color = 265;
	else if (keycode == 35)
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == 34)
		data->show_text = !data->show_text;
	return (0);
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		data->it_max += 50;
	else if (keycode == 78)
		data->it_max -= 50;
	else if (keycode == 123)
		data->x1 -= 30 / data->zoom;
	else if (keycode == 124)
		data->x1 += 30 / data->zoom;
	else if (keycode == 125)
		data->y1 += 30 / data->zoom;
	else if (keycode == 126)
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49)
		fract_init(data);
	else if (keycode == 18)
		data->color = 1677216;
	key_hook2(keycode, data);
	fract_calc(data);
	return (0);
}