/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 15:08:16 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 20:10:55 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# define ABS(x) ((x) < 0 ? -(x) : (x))

double	map(double x, double in_max, double out_min, double out_max);

#endif
