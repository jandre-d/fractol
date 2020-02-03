/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:07:18 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 20:38:50 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>

int		close(void *trash)
{
	(void)trash;
	exit(0);
}

void	alloc_map(t_win_properties *w_p)
{
	int32_t y;

	w_p->iteration_map = TAKE_MULTI(int32_t *, w_p->size_y, "null");
	if (w_p->iteration_map == NULL)
		error_malloc("null");
	y = 0;
	while (y < w_p->size_y)
	{
		w_p->iteration_map[y] = TAKE_MULTI(int32_t, w_p->size_x, "null");
		if (w_p->iteration_map[y] == NULL)
			error_malloc("null");
		y++;
	}
}

void	fract_init(t_win_properties *win_prop, int8_t large,
	int32_t (*fract_get_iter)(t_win_properties *, int32_t, int32_t))
{
	win_prop->size_x = large == 1 ? 1920 : 700;
	win_prop->size_y = large == 1 ? 1080 : 600;
	alloc_map(win_prop);
	win_prop->win_ptr = mlx_new_window(win_prop->program_mlx_ptr,
		win_prop->size_x, win_prop->size_y, "jandre-d");
	win_prop->img_ptr = mlx_new_image(win_prop->program_mlx_ptr,
		win_prop->size_x, win_prop->size_y);
	win_prop->img_array_ptr = image_get_data_ptr(win_prop->img_ptr);
	win_prop->fract_get_iter = fract_get_iter;
	win_prop->fract_state.zoom = 1;
	win_prop->fract_state.max_iterations = 50;
	win_prop->color_event = &fractol_offset_color;
	mlx_hook(win_prop->win_ptr, 2, 42, key_press, (void *)win_prop);
	mlx_hook(win_prop->win_ptr, 4, 42, mouse_press, (void *)win_prop);
	mlx_hook(win_prop->win_ptr, 6, 42, mouse_move, (void *)win_prop);
	mlx_hook(win_prop->win_ptr, 17, 42, close, (void *)win_prop);
}
