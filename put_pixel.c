/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:39 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/20 19:55:47 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->buffer + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// draw lines between points in the matrix (map) using Bresenham's line algorithm and my_mlx_pixel_put function
void	draw_line(t_dot **matrix, int rows, int columns, t_data *img)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			x = matrix[i][j].x;
			y = matrix[i][j].y;
			if (j + 1 < columns)
			{
				x1 = x;
				y1 = y;
				x2 = matrix[i][j + 1].x;
				y2 = matrix[i][j + 1].y;
				dx = abs(x2 - x1);
				dy = abs(y2 - y1);
				if (x1 < x2)
					sx = 1;
				else
					sx = -1;
				if (y1 < y2)
					sy = 1;
				else
					sy = -1;
				if (dx > dy)
					err = dx / 2;
				else
					err = -dy / 2;
				while (1)
				{
					my_mlx_pixel_put(img, x1, y1, matrix[i][j].color);
					if (x1 == x2 && y1 == y2)
						break ;
					e2 = err;
					if (e2 > -dx)
					{
						err -= dy;
						x1 += sx;
					}
					if (e2 < dy)
					{
						err += dx;
						y1 += sy;
					}
				}
			}
			if (i + 1 < rows)
			{
				x1 = x;
				y1 = y;
				x2 = matrix[i + 1][j].x;
				y2 = matrix[i + 1][j].y;
				dx = abs(x2 - x1);
				dy = abs(y2 - y1);
				if (x1 < x2)
					sx = 1;
				else
					sx = -1;
				if (y1 < y2)
					sy = 1;
				else
					sy = -1;
				if (dx > dy)
					err = dx / 2;
				else
					err = -dy / 2;
				while (1)
				{
					my_mlx_pixel_put(img, x1, y1, matrix[i][j].color);
					if (x1 == x2 && y1 == y2)
						break ;
					e2 = err;
					if (e2 > -dx)
					{
						err -= dy;
						x1 += sx;
					}
					if (e2 < dy)
					{
						err += dx;
						y1 += sy;
					}
				}
			}
			j++;
		}
		i++;
	}
}
void	put_pixel(t_dot **matrix, int rows, int columns)
{
	void	*mlx;
	void	*window;
	t_data	img;
	//int		i;
	//int		j;
	
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.buffer = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			my_mlx_pixel_put(&img, matrix[i][j].x, matrix[i][j].y, matrix[i][j].color);
			j++;
		}
		i++;
	}
	*/
	draw_line(matrix, rows, columns, &img);
	mlx_put_image_to_window(mlx, window, img.img, 0 , 0);
	mlx_loop(mlx);
}
