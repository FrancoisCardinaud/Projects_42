/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol 2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:15:52 by fcardina          #+#    #+#             */
/*   Updated: 2024/04/17 03:21:45 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600

typedef struct s_t
{
	unsigned char	*ch;
	double			x;
	double			y;
	double			x_x;
	double			y_y;
	void			*ptr;
	void			*win;
	double			x_o;
	double			y_o;
	int				itier;
	double			xtmp;
	double			ytmp;
	void			*image;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	char			*name;
	double			start_y;
	double			end_y;
	double			start_x;
	double			end_x;
	int				zoom;
	int				stop;
	int				max;
	int				color;
}					t_t;

void				check_ar(t_t *t);
void				destroy_exit(t_t *t);
double				ft_abs(double x);
void				init(t_t *t, char *str);
void				init_x_y(t_t *t);
void				itier_loop(t_t *t);
void				julia(t_t *t);
int					key_press(int keycode, t_t *t);
void				key_press2(int keycode, t_t *t);
void				key_press3(int keycode, t_t *t);
void				key_press4(int keycode, t_t *t);
void				mandelbrot(t_t *t);
void				map(t_t *t);
void				menu(t_t *t);
void				mlx_ho(t_t *t);
int					mouse_move(int x, int y, t_t *t);
int					mouse_press(int button, int x, int y, t_t *t);
void				set_color(t_t *t, int color);
void				simple_zoom1(t_t *t);
void				simple_zoom2(t_t *t);
void				string_put(t_t *t);
void				string1_put(t_t *t);
void				zoom(t_t *t, double x, double y, double zoom);

#endif
