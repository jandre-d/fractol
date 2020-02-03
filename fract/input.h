/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:24:37 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:02:06 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "../data_types.h"
# include "controll.h"
# include "../math.h"

int	mouse_press(int button, int x, int y, void *win_prop);
int	mouse_move(int x, int y, void *win_prop);
int	key_press(int key, void *win_prop);

#endif
