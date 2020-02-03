/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 16:27:40 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:48:34 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "data_types.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include "fract/init.h"
#include "fract/fractols.h"
#include "image.h"
#include "error.h"
#include <stdlib.h>
#include <pthread.h>

t_win_properties	*window_list_add_new(t_win_list *list)
{
	t_win_elem *use_me;
	t_win_elem *new;

	new = TAKE(t_win_elem, "main.c - window_list_add_new - TAKE");
	if (new == NULL)
	{
		error_malloc("main.c - window_list_add_new - TAKE");
	}
	if (list->window_list == NULL)
	{
		list->window_list = new;
	}
	else
	{
		use_me = list->window_list;
		while (use_me->next != NULL)
		{
			use_me = use_me->next;
		}
		use_me->next = new;
	}
	return (&new->win);
}

static void			exit_show_useage(void)
{
	ft_putstr("Usage:\n	Any amount of these flags:\n");
	ft_putstr("		-julia for the julia set \n");
	ft_putstr("		-mandel for the mandelbrot set\n");
	ft_putstr("		-ship for the burning ship fractal \n");
	ft_putstr(" add L to flag for a bigger window\n");
	exit(1);
}

static void			open_window(t_win_properties *win_prop, char *arg)
{
	if ((ft_strlen(arg) == ft_strlen("-julia")) &&
		ft_strcmp(arg, "-julia") == 0)
		fract_init(win_prop, 0, &julia_get_iterations);
	else if ((ft_strlen(arg) == ft_strlen("-mandel")) &&
		ft_strcmp(arg, "-mandel") == 0)
		fract_init(win_prop, 0, &mandelbrot_get_iterations);
	else if ((ft_strlen(arg) == ft_strlen("-ship")) &&
		ft_strcmp(arg, "-ship") == 0)
		fract_init(win_prop, 0, &burning_ship_get_iterations);
	else if ((ft_strlen(arg) == ft_strlen("-juliaL")) &&
		ft_strcmp(arg, "-juliaL") == 0)
		fract_init(win_prop, 1, &julia_get_iterations);
	else if ((ft_strlen(arg) == ft_strlen("-mandelL")) &&
		ft_strcmp(arg, "-mandelL") == 0)
		fract_init(win_prop, 1, &mandelbrot_get_iterations);
	else if ((ft_strlen(arg) == ft_strlen("-shipL")) &&
		ft_strcmp(arg, "-shipL") == 0)
		fract_init(win_prop, 1, &burning_ship_get_iterations);
	else
	{
		exit_show_useage();
	}
}

int					call_window_events(void *param)
{
	t_win_list			*list;
	t_win_elem			*loop;

	list = (t_win_list *)param;
	if (list->counter == 400)
	{
		if (list->window_list == NULL)
			return (1);
		loop = list->window_list;
		while (loop != NULL)
		{
			loop->win.color_event(&loop->win);
			loop = loop->next;
		}
		list->counter = 0;
	}
	list->counter++;
	return (0);
}

int					main(int argc, char **argv)
{
	void				*mlx_ptr;
	t_win_list			list;
	t_win_properties	*new;
	int					i;

	list.window_list = NULL;
	list.counter = 0;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		error_malloc("main.c - main - mlx_init");
	if (argc == 1)
		exit_show_useage();
	i = 1;
	while (i < argc)
	{
		new = window_list_add_new(&list);
		new->program_mlx_ptr = mlx_ptr;
		open_window(new, argv[i]);
		i++;
	}
	mlx_loop_hook(mlx_ptr, call_window_events, (void *)&list);
	mlx_loop(mlx_ptr);
	return (0);
}
