/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_types.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 15:57:29 by jandre-d       #+#    #+#                */
/*   Updated: 2019/03/30 21:49:52 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPES_H
# define DATA_TYPES_H
# include <stdint.h>
# include <pthread.h>
# define TAKE(x, name) ((x*)ft_memalloc(sizeof(x)))
# define TAKE_MULTI(x, times, name) ((x*)(ft_memalloc(sizeof(x) * times)))
# define GIVE(x, name) ft_memdel((void **)&(x))
# define TRUE 1
# define FALSE 0

typedef uint8_t	t_bool;

typedef struct	s_fractal_state
{
	int32_t	max_iterations;
	uint8_t color_offset;
	t_bool	lock_position;
	double	c_real;
	double	c_imaginary;
	double	zoom;
	double	move_x;
	double	move_y;
}				t_fractal_state;

typedef struct	s_fractol_vars
{
	double		real;
	double		imaginary;
	int32_t		iteration;
	int32_t		max_iteration;
	double		re_temp;
	double		im_temp;
}				t_fractol_vars;

typedef struct	s_win_properties
{
	void			(*color_event)(struct s_win_properties *);
	int32_t			(*fract_get_iter)(struct s_win_properties *,
		int32_t, int32_t);
	t_fractal_state	fract_state;
	void			*program_mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int32_t			**iteration_map;
	int32_t			size_x;
	int32_t			size_y;
	uint32_t		*img_array_ptr;
}				t_win_properties;

typedef struct	s_render_thread_param
{
	t_win_properties	*w_p;
	int32_t				y_start;
	int32_t				y_end;
}				t_render_thread_param;

typedef struct	s_color_hsv
{
	uint8_t h;
	uint8_t s;
	uint8_t v;
}				t_color_hsv;

typedef struct	s_win_elem
{
	t_win_properties		win;
	struct s_win_elem		*next;
}				t_win_elem;

typedef struct	s_win_list
{
	t_win_elem	*window_list;
	int			counter;
}				t_win_list;

#endif
