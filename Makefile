# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jandre-d <jandre-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/30 21:54:59 by jandre-d       #+#    #+#                 #
#    Updated: 2019/04/01 15:03:02 by jandre-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FILES = color error image main math fract/controll fract/fractols fract/init \
	fract/input

$(NAME):
	cd minilibx_macos && make
	cd libft && make
	gcc $(FILES:=.c) -lmlx -lft -framework OpenGl -framework AppKit \
		-L minilibx_macos/ -Ofast -L libft/ -o $(NAME)

clean:
	cd minilibx_macos && make clean
	cd libft && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
