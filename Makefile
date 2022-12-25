NAME = fdf

LIBFT = libft.a

SRCS = 	main.c 			\
		put_pixel.c 	\
		read_map.c		\
		get_lines.c		\
		get_columns.c	\
		isometric.c		\
		pixel_aux.c

OBJS = ${SRCS:.c=.o}

all:
	@make -C libft/ all
	@mv libft/libft.a libft.a
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRCS)
	@gcc -o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm 
test: all
	@make fclean
	@clear
	@./fdf maps/42.fdf
clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -f $(LIBFT)
	@make -C libft/ fclean

re: fclean all

push:
	@./script_git.sh
