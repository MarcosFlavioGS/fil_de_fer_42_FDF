all: name

name:
	gcc -Iminilibx-linux -c main.c
	gcc main.o -Lminilibx-linux -lmlx -lXext -lX11 
clean:
	rm -rf *.o a.out
fclean:

re:
