/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:14:06 by fcardina          #+#    #+#             */
/*   Updated: 2023/04/05 18:03:47 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_press(int button, int x, int y, t_t *t)
{
	if (button == 5 && t->stop == 1)
		zoom(t, (double)x, (double)y, 1.1);
	else if (button == 4 && t->stop == 1)
		zoom(t, (double)x, (double)y, 0.9);
	check_ar(t);
	return (1);
}

void	key_press2(int keycode, t_t *t)
{
	if (keycode == 124)
	{
		t->start_x = t->start_x - 0.037;
		t->end_x = t->end_x - 0.037;
		check_ar(t);
	}
	else if (keycode == 125)
	{
		t->start_y = t->start_y - 0.037;
		t->end_y = t->end_y - 0.037;
		check_ar(t);
	}
	else if (keycode == 126)
	{
		t->start_y = t->start_y + 0.037;
		t->end_y = t->end_y + 0.037;
		check_ar(t);
	}
	else if (keycode == 24)
	{
		t->max += 10;
		check_ar(t);
	}
	else
		key_press3(keycode, t);
}

int	key_press(int keycode, t_t *t)
{
	if (keycode == 53)
	{
		destroy_exit(t);
		exit(0);
	}
	else if (keycode == 69 && t->stop == 1)
	{
		simple_zoom1(t);
		check_ar(t);
	}
	else if (keycode == 78 && t->stop == 1)
	{
		simple_zoom2(t);
		check_ar(t);
	}
	else if (keycode == 27)
	{
		if (t->max >= 10)
			t->max -= 10;
		check_ar(t);
	}
	else
		key_press2(keycode, t);
	return (1);
}

void	key_press3(int keycode, t_t *t)
{
	if (keycode == 83)
	{
		t->name = "Julia";
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 49)
	{
		if (t->stop == 0)
			t->stop = 1;
		else
			t->stop = 0;
		check_ar(t);
	}
	else if (keycode == 36)
	{
		t->color = rand();
		check_ar(t);
	}
	else
		key_press4(keycode, t);
}

void	key_press4(int keycode, t_t *t)
{
	/*if (keycode == 84)
	{
		t->name = "Burningship";
		init(t, t->name);
		check_ar(t);
	}
	else */if (keycode == 85)
	{
		t->name = "Mandelbrot";
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 82)
	{
		init(t, t->name);
		check_ar(t);
	}
	else if (keycode == 123)
	{
		t->start_x = t->start_x + 0.037;
		t->end_x = t->end_x + 0.037;
		check_ar(t);
	}
}

/*This C code defines a series of functions that handle key presses 
in a graphical application. The key_press function is the main function 
that is called when a key is pressed. It takes an integer keycode and 
a pointer to a t_t struct as arguments. The t_t struct contains information 
about the application's state, such as the current zoom level and the 
type of fractal being displayed.

The key_press function checks the value of keycode using conditional 
statements (if, else if, and else) and calls other functions based on 
the key that was pressed. For example, if the keycode is 53, the 
destroy_exit function is called, which exits the application. If the 
keycode is 69, the simple_zoom1 function is called, which zooms in 
on the fractal. If the keycode is none of the above, the key_press2 
function is called to check if the key code corresponds to one of the 
fractal manipulation actions.

The key_press2 function also checks the keycode value and manipulates 
the t_t struct accordingly. For example, if the keycode is 124, the 
start_x and end_x values in the t_t struct are decreased by 0.037, 
which has the effect of panning the fractal to the left. The check_ar 
function is called after each manipulation to update the fractal display.

The key_press3 and key_press4 functions are called from key_press2 
and handle additional key codes that are not directly related to 
fractal manipulation. For example, if the keycode is 83, the name 
field in the t_t struct is set to "Julia", which changes the type of 
fractal being displayed to a Julia set. If the keycode is 36, the 
color field in the t_t struct is set to a random value, which changes 
the color of the fractal.

Overall, these functions handle user input and update the application's 
state accordingly to display and manipulate fractals.*/