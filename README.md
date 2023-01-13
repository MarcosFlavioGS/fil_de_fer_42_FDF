
# fil_de_fer_42_FDF

## This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

###

This is th fifth project in 42 curriculumn. The goal is to code a 3D wireframe projection of a landscape using thw school's internal libray [MinilibX](https://github.com/42Paris/minilibx-linux). This library is made for window management in C, so that it is possible to print pixels directly on a window.

# The Norm

For every project at 42, we need to follow the [Norm](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf). The *Norm* is a set of programing standards that every 42 student(cadet) needs to follow on every project.

# Libft

This project is made using [Libft](https://github.com/MarcosFlavioGS/Libft). Libft is a set of recoded C functions, it is one of 42 projects.

# FDF

## How does it work ?

This program simply takes any *.fdf* file and reads it into a 2D matrix using *[get_next_line](https://github.com/MarcosFlavioGS/Get_next_line_42)*, then uses it to print pixels on the screen in isometric projection format. A *.fdf* file is a text file with numbers, each number represents a point in space, with *X* and *Y* positions determined by the position on the file and its hight, represented by the value.

## Projection

The Isometric projection is made using a simple formula:
```c
      x = (x - y) * cos(0.6);
			y = (x + y) * sin(0.5) - z;
			x += 600;
			y += 100;
```
## Lining

To connect each *dot* with lines I used the [Bresenham Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

## How to use it

To use the program, simply:

```c
./fdf <yourfile.fdf>
```
