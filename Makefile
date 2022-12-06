NAME = fdf

SRC = put_pixel.c

all: name

name:
	gcc -Wall -Wextra -Werror -Iminilibx-linux -c main.c $(SRC)
	gcc -o $(NAME) main.o put_pixel.o -Lminilibx-linux -lmlx -lXext -lX11 -lm 
clean:
	rm -rf *.o
fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

push:
	read message
	git add .
	git status
	git commit -m $message
	git push
