# fil_de_fer_42_FDF

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://github.com/MarcosFlavioGS/fil_de_fer_42_FDF/blob/master/github_imgs/fdfn.png">
	
<p align="center"><img src="https://github.com/MarcosFlavioGS/fil_de_fer_42_FDF/blob/master/github_imgs/Capturar.PNG">

## This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

###

This is the fifth project in 42 curriculumn. The goal is to code a 3D wireframe projection of a landscape using thw school's internal libray [MinilibX](https://github.com/42Paris/minilibx-linux). This library is made for window management in C, so that it is possible to print pixels directly on a window.

# The Norm

For every project at 42, we need to follow the [Norm](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf). The *Norm* is a set of programing standards that every 42 student(cadet) needs to follow on every project.

# Libft

This project is made using [Libft](https://github.com/MarcosFlavioGS/Libft). Libft is a set of recoded C functions, it is one of 42 projects.

# FDF

## How does it work ?

This program simply takes any *.fdf* file and reads it into a 2D matrix using *[get_next_line](https://github.com/MarcosFlavioGS/Get_next_line_42)*, then uses it to print pixels on the screen in isometric projection format.

A *.fdf* file is a text file with numbers, each number represents a point in space, with *X* and *Y* positions determined by the position on the file and its hight, represented by the value:

*42.fdf*
```txt
		0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
		0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
		0  0 30 30  0  0 30 30  0  0  0 30 30 30 30 30  0  0  0
		0  0 30 30  0  0 30 30  0  0  0  0  0  0  0 30 30  0  0
		0  0 30 30  0  0 30 30  0  0  0  0  0  0  0 30 30  0  0
		0  0 30 30 30 30 30 30  0  0  0  0 30 30 30 30  0  0  0
		0  0  0 30 30 30 30 30  0  0  0 30 30  0  0  0  0  0  0
		0  0  0  0  0  0 30 30  0  0  0 30 30  0  0  0  0  0  0
		0  0  0  0  0  0 30 30  0  0  0 30 30 30 30 30 30  0  0
		0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
		0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Maps can also contain hexadecimal values representing colors. These values must be separated from the height values only by a comma:

```txt
	 1,0xff 1,0xff 2,0xff 1,0xff 3,0xff 9,0xff00 9,0xff00
	 0,0xff 1,0xff 1,0xff 7,0xff00 7,0xff00 5,0xff00 10,0xff00
	 0,0xff 0,0xff 0,0xff 6,0xff00 5,0xff00 9,0xff00 9,0xff00
```
*t1.fdf*
<p align="center"><img src="https://github.com/MarcosFlavioGS/fil_de_fer_42_FDF/blob/master/github_imgs/t1.PNG">

*t2.fdf*
<p align="center"><img src="https://github.com/MarcosFlavioGS/fil_de_fer_42_FDF/blob/master/github_imgs/t2.PNG">

## Projection

The Isometric projection is made using a simple formula:
```c
      			x = (x - y) * cos(0.6);
			y = (x + y) * sin(0.5) - z;
```

*mars.fdf*
<p align="center"><img src="https://github.com/MarcosFlavioGS/fil_de_fer_42_FDF/blob/master/github_imgs/Marswhite.PNG">

## Lining

To connect each *dot* with lines I used the [Bresenham's Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

## How to use it

To use the program, simply:

```sh
./fdf <yourfile.fdf>
```
