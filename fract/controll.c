/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controll.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:02:30 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:01:06 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "controll.h"

void	fractol_offset_color(t_win_properties *win_prop)
{
	win_prop->fract_state.color_offset += 4;
	draw_fract(win_prop);
	image_push(win_prop);
}

void	draw_fract(t_win_properties *w_p)
{
	int32_t y;
	int32_t x;

	y = 0;
	while (y < w_p->size_y)
	{
		x = 0;
		while (x < w_p->size_x)
		{
			image_set_pixel(w_p, x, y, get_color_from_iterations(
				w_p->iteration_map[y][x], w_p->fract_state.max_iterations,
					w_p->fract_state.color_offset));
			x++;
		}
		y++;
	}
	image_push(w_p);
}

void	*render_func(void *void_param)
{
	t_render_thread_param	*param;
	t_win_properties		*w_p;
	int32_t					y;
	int32_t					x;

	param = (t_render_thread_param *)void_param;
	w_p = param->w_p;
	y = param->y_start;
	while (y < param->y_end)
	{
		x = 0;
		while (x < w_p->size_x)
		{
			w_p->iteration_map[y][x] = w_p->fract_get_iter(w_p, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	calc_fract(t_win_properties *w_p)
{
	t_render_thread_param	render_param[42];
	pthread_t				threads[42];
	int32_t					step_size;
	int32_t					i;

	step_size = w_p->size_y / 42;
	i = 0;
	while (i < 41)
	{
		render_param[i].w_p = w_p;
		render_param[i].y_start = i * step_size;
		render_param[i].y_end = render_param[i].y_start + step_size;
		pthread_create(&threads[i], NULL, render_func,
			(void *)&render_param[i]);
		i++;
	}
	render_param[41].w_p = w_p;
	render_param[41].y_start = 41 * step_size;
	render_param[41].y_end = w_p->size_y;
	pthread_create(&threads[41], NULL, render_func, (void *)&render_param[41]);
	i = 0;
	while (i < 42)
		pthread_join(threads[i++], NULL);
	draw_fract(w_p);
	image_push(w_p);
}
