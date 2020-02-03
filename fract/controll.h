/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controll.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:02:27 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:01:01 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLL_H
# define CONTROLL_H
# include "../data_types.h"
# include "../image.h"
# include "../color.h"

void	fractol_offset_color(t_win_properties *win_prop);
void	draw_fract(t_win_properties *w_p);
void	*render_func(void *void_param);
void	calc_fract(t_win_properties *w_p);

#endif
