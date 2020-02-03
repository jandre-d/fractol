/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:07:21 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 20:35:29 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "../data_types.h"
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../error.h"
# include "controll.h"
# include "input.h"

void	fract_init(t_win_properties *win_prop, int8_t large,
	int32_t (*fract_get_iter)(t_win_properties *, int32_t, int32_t));

#endif
