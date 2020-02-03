/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 15:08:08 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 20:10:43 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	map(double x, double in_max, double out_min, double out_max)
{
	return (x * (out_max - out_min) / in_max + out_min);
}
