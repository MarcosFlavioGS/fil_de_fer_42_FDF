all: name

name:
	gcc -Wall -Wextra -Werror -Iminilibx-linux -c main.c
	gcc -o fdf main.o -Lminilibx-linux -lmlx -lXext -lX11 
clean:
	rm -rf *.o
fclean: clean

re:
