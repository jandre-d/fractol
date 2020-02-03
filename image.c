/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 09:21:54 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 20:10:01 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#define BPP 4

uint32_t		*image_get_data_ptr(void *img_ptr)
{
	int32_t trash;

	return ((uint32_t *)mlx_get_data_addr(img_ptr,
		&trash, &trash, &trash));
}

int				image_push(t_win_properties *w_prop)
{
	return (mlx_put_image_to_window(w_prop->program_mlx_ptr, w_prop->win_ptr,
		w_prop->img_ptr, 0, 0));
}

void			image_set_pixel(t_win_properties *w_prop, int32_t x, int32_t y,
	uint32_t color)
{
	if (y < w_prop->size_y && x < w_prop->size_x && y > 0 && x > 0)
		w_prop->img_array_ptr[y * w_prop->size_x + x] = color;
}

void			image_clear(t_win_properties *w_prop)
{
	ft_memset((void *)w_prop->img_array_ptr, 0,
		w_prop->size_x * w_prop->size_y * BPP);
}
