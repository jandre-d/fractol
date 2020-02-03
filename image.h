/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 09:20:44 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/24 15:02:22 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "data_types.h"
# include <stdint.h>

uint32_t		*image_get_data_ptr(void *img_ptr);
int				image_push(t_win_properties *w_prop);
void			image_set_pixel(t_win_properties *w_prop, int32_t x, int32_t y,
	uint32_t color);
void			image_clear(t_win_properties *w_prop);

#endif
