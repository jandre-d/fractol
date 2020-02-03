/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 14:17:37 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:41:26 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft/libft.h"
#include <stdlib.h>

void	error_malloc(char *where)
{
	ft_putstr("\n\nERROR!!! Malloc failed at: ");
	ft_putstr((const char *)where);
	exit(1);
}

void	error_general(char *msg, char *where)
{
	ft_putstr("\n\nERROR : ");
	ft_putstr(msg);
	ft_putstr("\n at : ");
	ft_putstr(where);
	exit(1);
}
