/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:00:23 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:46:25 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>

static void		get(double rr, double gg, double bb, uint32_t *to_return)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;

	r = rr * 255;
	g = gg * 255;
	b = bb * 255;
	*to_return = ((r << 16) | (g << 8) | b);
}

static void		color_from_hsv(uint8_t h, uint8_t s, uint8_t v,
	uint32_t *to_return)
{
	t_hsv_convert_vars x;

	x.s = s / 256.0;
	x.v = v / 256.0;
	x.h = (h / 256.0) * 6;
	x.i = (int)(x.h);
	x.f = x.h - x.i;
	x.p = x.v * (1 - x.s);
	x.q = x.v * (1 - (x.s * x.f));
	x.t = x.v * (1 - (x.s * (1 - x.f)));
	get(x.v, x.v, x.v, to_return);
	if (x.s == 0)
		return ;
	if (x.i == 0)
		get(x.v, x.t, x.p, to_return);
	if (x.i == 1)
		get(x.q, x.v, x.p, to_return);
	if (x.i == 2)
		get(x.p, x.v, x.t, to_return);
	if (x.i == 3)
		get(x.p, x.q, x.v, to_return);
	if (x.i == 4)
		get(x.t, x.p, x.v, to_return);
	if (x.i == 5)
		get(x.v, x.p, x.q, to_return);
}

uint32_t		get_color_from_iterations(int32_t iter, int32_t max_iter,
	int32_t offset)
{
	uint32_t to_return;

	color_from_hsv((iter + offset) % 256, 255, 255 * (iter < max_iter),
		&to_return);
	return (to_return);
}
