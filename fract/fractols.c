/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractols.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:54:42 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 19:40:02 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

int			mandelbrot_get_iterations(t_win_properties *w_p, int x, int y)
{
	t_fractol_vars	vars;
	t_fractal_state	*state;

	ft_bzero((void *)&vars, sizeof(t_fractol_vars));
	state = &w_p->fract_state;
	state->c_real = 1.5 * (x - w_p->size_x / 2) / (0.5 * state->zoom *
		w_p->size_x) + state->move_x;
	state->c_imaginary = (y - w_p->size_y / 2) / (0.5 * state->zoom *
		w_p->size_y) + state->move_y;
	vars.real = 0;
	vars.imaginary = 0;
	vars.re_temp = 0;
	vars.im_temp = 0;
	while (vars.real * vars.real + vars.imaginary * vars.imaginary <= 4 &&
		vars.iteration < state->max_iterations)
	{
		vars.re_temp = vars.real;
		vars.im_temp = vars.imaginary;
		vars.real = vars.re_temp * vars.re_temp - vars.im_temp *
			vars.im_temp + state->c_real;
		vars.imaginary = 2 * vars.re_temp *
			vars.im_temp + state->c_imaginary;
		vars.iteration++;
	}
	return (vars.iteration);
}

int			julia_get_iterations(t_win_properties *w_p, int x, int y)
{
	t_fractol_vars	vars;
	t_fractal_state	*state;

	ft_bzero((void *)&vars, sizeof(t_fractol_vars));
	state = &w_p->fract_state;
	vars.real = 1.5 * (x - w_p->size_x / 2) / (0.5 * state->zoom *
		w_p->size_x) + state->move_x;
	vars.imaginary = (y - w_p->size_y / 2) / (0.5 * state->zoom *
		w_p->size_y) + state->move_y;
	while (vars.real * vars.real + vars.imaginary * vars.imaginary <= 4 &&
		vars.iteration < state->max_iterations)
	{
		vars.re_temp = vars.real;
		vars.im_temp = vars.imaginary;
		vars.real = vars.re_temp * vars.re_temp - vars.im_temp *
			vars.im_temp + state->c_real;
		vars.imaginary = 2 * vars.re_temp *
			vars.im_temp + state->c_imaginary;
		vars.iteration++;
	}
	return (vars.iteration);
}

int			burning_ship_get_iterations(t_win_properties *w_p, int x, int y)
{
	t_fractol_vars	vars;
	t_fractal_state	*state;

	ft_bzero((void *)&vars, sizeof(t_fractol_vars));
	state = &w_p->fract_state;
	state->c_real = 1.5 * (x - w_p->size_x / 2) / (0.5 * state->zoom *
		w_p->size_x) + state->move_x;
	state->c_imaginary = (y - w_p->size_y / 2) / (0.5 * state->zoom *
		w_p->size_y) + state->move_y;
	vars.real = 0;
	vars.imaginary = 0;
	vars.re_temp = 0;
	vars.im_temp = 0;
	while (vars.real * vars.real + vars.imaginary * vars.imaginary <= 4 &&
		vars.iteration < state->max_iterations)
	{
		vars.re_temp = vars.real;
		vars.im_temp = vars.imaginary;
		vars.real = ABS(vars.re_temp * vars.re_temp - vars.im_temp *
			vars.im_temp) + state->c_real;
		vars.imaginary = ABS(2 * vars.re_temp *
			vars.im_temp) + state->c_imaginary;
		vars.iteration++;
	}
	return (vars.iteration);
}
