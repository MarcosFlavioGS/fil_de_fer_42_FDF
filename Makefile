NAME = fdf

LIBFT = libft.a

SRCS = 	main.c \
		put_pixel.c

OBJS = ${SRCS:.c=.o}

all:
	@make -C libft/ all
	@mv libft/libft.a libft.a
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRCS)
	@gcc -o $(NAME) $(OBJS) $(LIBFT) -Lminilibx-linux -lmlx -lXext -lX11 -lm 
test:
	@make -C libft/ all
	@mv libft/libft.a libft.a
	@gcc -o teste main.c $(LIBFT)
	@make fclean
	@clear
	@./teste maps/42.fdf
clean:
	@rm -rf *.o
fclean: clean
	@rm -f $(NAME) libft.a
	@make -C libft/ fclean

re: fclean all

push:
	@./script_git.sh
