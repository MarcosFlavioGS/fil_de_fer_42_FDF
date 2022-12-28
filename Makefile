NAME = fdf

LIBFT = libft.a

SRCS = 	main.c 			\
		put_pixel.c 	\
		read_map.c		\
		get_lines.c		\
		get_columns.c	\
		isometric.c		\
		pixel_aux.c		\
		close_window.c	\
		mlx_init.c		\
		move_map.c				

OBJS = ${SRCS:.c=.o}

all:
	@make -C libft/ all
	@cp libft/libft.a libft.a
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRCS)
	@gcc -o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm 
test: all
	@make fclean
	@clear
	@./fdf maps/42.fdf
leak:
	@make -C libft/ all
	@mv libft/libft.a libft.a
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRCS)
	@gcc -o $(NAME) -g $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm
	@make fclean
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --show-reachable=no --track-origins=yes ./fdf maps/42.fdf
clean:
	@rm -rf $(OBJS)
	@make -C libft/ clean
fclean: clean
	@rm -f $(LIBFT)
	@make -C libft/ fclean

re: fclean all

push:
	@./script_git.sh
