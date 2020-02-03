/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:00:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:39:34 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "./data_types.h"

typedef struct	s_hsv_convert_vars
{
	double	r;
	double	g;
	double	b;
	double	h;
	double	s;
	double	v;
	double	f;
	double	p;
	double	q;
	double	t;
	int		i;
}				t_hsv_convert_vars;

uint32_t		get_color_from_iterations(int32_t iter, int32_t max_iter,
	int32_t offset);

#endif
