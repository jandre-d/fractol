/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractols.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:54:40 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 19:55:06 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLS_H
# define FRACTOLS_H
# include "../data_types.h"
# include "../libft/libft.h"
# include "../math.h"

int			mandelbrot_get_iterations(t_win_properties *w_p, int x, int y);
int			julia_get_iterations(t_win_properties *w_p, int x, int y);
int			burning_ship_get_iterations(t_win_properties *w_p, int x, int y);

#endif
