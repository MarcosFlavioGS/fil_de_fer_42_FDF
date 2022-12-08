NAME = fdf

SRC = 	main.c \
		put_pixel.c

all: name

name:
	@make -C libft/ all
	@mv libft/libft.a libft.a
	@gcc -Wall -Wextra -Werror -Iminilibx-linux -c $(SRC)
	@gcc -o $(NAME) main.o libft.a put_pixel.o -Lminilibx-linux -lmlx -lXext -lX11 -lm 
test:
	@make -C libft/ all
	@mv libft/libft.a libft.a
	gcc -o teste main.c libft.a
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
