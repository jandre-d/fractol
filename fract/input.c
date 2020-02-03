/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:24:34 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 20:58:57 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <stdlib.h>

int	mouse_press(int button, int x, int y, void *win_prop)
{
	t_win_properties	*w_p;
	t_fractal_state		*fs;
	double				move_x;
	double				move_y;

	w_p = (t_win_properties *)win_prop;
	fs = (t_fractal_state *)&w_p->fract_state;
	move_x = map(ABS(x - w_p->size_x / 2), w_p->size_x / 2, 0, .25) / fs->zoom;
	move_y = map(ABS(y - w_p->size_y / 2), w_p->size_y / 2, 0, .25) / fs->zoom;
	if (button == 5)
	{
		fs->zoom += .1 * fs->zoom;
		fs->move_x += (x - w_p->size_x / 2) > 0 ? move_x : -move_x;
		fs->move_y += (y - w_p->size_y / 2) > 0 ? move_y : -move_y;
	}
	if (button == 4)
	{
		if (fs->zoom > 0)
			fs->zoom -= .1 * fs->zoom;
		fs->move_x += (x - w_p->size_x / 2) > 0 ? -move_x : move_x;
		fs->move_y += (y - w_p->size_y / 2) > 0 ? -move_y : move_y;
	}
	calc_fract(w_p);
	draw_fract(w_p);
	return (0);
}

int	mouse_move(int x, int y, void *win_prop)
{
	t_win_properties *w_p;

	w_p = (t_win_properties *)win_prop;
	if (w_p->fract_state.lock_position == TRUE)
		return (0);
	if (x < 0)
		x = 0;
	if (x > w_p->size_x)
		x = w_p->size_x;
	if (y < 0)
		y = 0;
	if (y > w_p->size_y)
		y = w_p->size_y;
	w_p->fract_state.c_real = map(x, w_p->size_x, -2.5, 1);
	w_p->fract_state.c_imaginary = map(y, w_p->size_y, -1, 1);
	calc_fract(w_p);
	draw_fract(w_p);
	return (0);
}

int	key_press(int key, void *win_prop)
{
	t_win_properties	*w_p;
	t_fractal_state		*state;

	w_p = (t_win_properties *)win_prop;
	state = (t_fractal_state *)&w_p->fract_state;
	if (key == 53)
		exit(0);
	if (key == 49)
		state->lock_position = state->lock_position == TRUE ? FALSE : TRUE;
	if (key == 126)
		state->move_y -= .5 / state->zoom;
	if (key == 125)
		state->move_y += .5 / state->zoom;
	if (key == 123)
		state->move_x -= .5 / state->zoom;
	if (key == 124)
		state->move_x += .5 / state->zoom;
	if (key == 24)
		state->max_iterations += 5;
	if (key == 27 && state->max_iterations > 5)
		state->max_iterations -= 5;
	calc_fract(w_p);
	draw_fract(w_p);
	return (0);
}
