# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 19:52:55 by mflavio-          #+#    #+#              #
#    Updated: 2023/02/02 20:06:05 by mflavio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft/libft.a

SRCS = 	main.c 				\
		put_pixel.c 		\
		read_map.c			\
		get_lines.c			\
		get_columns.c		\
		isometric.c			\
		pixel_aux.c			\
		close_window.c		\
		mlx_init.c			\
		move_map.c			\
		check_extension.c	\
		ft_error.c		

OBJS = ${SRCS:.c=.o}

BSRCS = main_bonus.c 		\
		put_pixel.c 		\
		read_map.c			\
		get_lines.c			\
		get_columns.c		\
		parallel.c			\
		pixel_aux.c			\
		close_window.c		\
		mlx_init.c			\
		move_map.c			\
		check_extension.c	\
		ft_error.c		

BOBJS = ${BSRCS:.c=.o}

all:
	@make -C libft/ all
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRCS)
	@gcc -o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm 
test: all
	@make clean
	@clear
	@echo "Starting tests..."
	@echo "Testing 42.fdf"
	@sleep 1
	@./fdf maps/42.fdf
	@clear
	@echo "Testing mars.fdf"
	@sleep 2
	@./fdf maps/mars.fdf
	@clear
	@echo "Testing pyramid.fdf"
	@sleep 2
	@./fdf maps/pyramide.fdf
	@clear
	@echo "Testing pylone.fdf"
	@sleep 2
	@./fdf maps/pylone.fdf
	@clear
	@echo "Testing 100-6.fdf"
	@sleep 2
	@./fdf maps/100-6.fdf
	@clear
	@echo "Testing elem2.fdf"
	@sleep 2
	@./fdf maps/elem2.fdf
	@clear
	@echo "Testing elem-col.fdf"
	@sleep 2
	@./fdf maps/elem-col.fdf
	@clear
	@echo "Testing t1.fdf"
	@sleep 2
	@./fdf maps/t1.fdf
	@clear
	@echo "Testing t2.fdf"
	@sleep 2
	@./fdf maps/t2.fdf
	@clear
	@echo "Testing julia.fdf, this may take a while... Go get a coffee"
	@sleep 3
	@./fdf maps/julia.fdf
	@clear
	@echo 'Tests finished !!'
	@sleep 1
	@make fclean
	@clear
leak:
	@make -C libft/ all
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -g3 -c $(SRCS)
	@gcc -o $(NAME) -g $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm
	@make clean
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes ./fdf maps/42.fdf
bonus:
	@make -C libft/ all
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(BSRCS)
	@gcc -o $(NAME) $(BOBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm 
clean:
	@rm -rf $(OBJS)
	@rm -rf $(BOBJS)
	@make -C libft/ clean
fclean: clean
	@rm -f $(LIBFT)
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all
