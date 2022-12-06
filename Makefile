NAME = fdf

SRC = 	main.c \
		put_pixel.c

all: name

name:
	@make -C libft/ all
	gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRC)
	gcc -o $(NAME) main.o put_pixel.o -Lminilibx-linux -lmlx -lXext -lX11 -lm 
clean:
	rm -rf *.o
fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
