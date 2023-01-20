# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 19:40:04 by mflavio-          #+#    #+#              #
#    Updated: 2023/01/20 19:40:10 by mflavio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		move_map.c		\
		ft_error.c		

OBJS = ${SRCS:.c=.o}

all:
	@make -C libft/ all
	@cp libft/libft.a libft.a
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRCS)
	@gcc -o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm 
test: all
	@make fclean
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
leak:
	@make -C libft/ all
	@mv libft/libft.a libft.a
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -g3 -c $(SRCS)
	@gcc -o $(NAME) -g $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm
	@make fclean
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes ./fdf maps/42.fdf
clean:
	@rm -rf $(OBJS)
	@make -C libft/ clean
fclean: clean
	@rm -f $(LIBFT)
	@make -C libft/ fclean

re: fclean all
