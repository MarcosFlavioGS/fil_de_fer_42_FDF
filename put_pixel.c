/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:39 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/23 23:37:34 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->buffer + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	setter(t_params *p, t_dot **matrix, int i, int j)
{
	p->x1 = p->x;
	p->y1 = p->y;
	p->x2 = matrix[i][j].x;
	p->y2 = matrix[i][j].y;
	p->dx = abs(p->x2 - p->x1);
	p->dy = abs(p->y2 - p->y1);
}

void	liner(t_params p, t_data *img, int color)
{
	while (1)
	{
		my_mlx_pixel_put(img, p.x1, p.y1, color);
		if (p.x1 == p.x2 && p.y1 == p.y2)
			break ;
		p.e2 = p.err;
		if (p.e2 > -p.dx)
		{
			p.err -= p.dy;
			p.x1 += p.sx;
		}
		if (p.e2 < p.dy)
		{
			p.err += p.dx;
			p.y1 += p.sy;
		}
	}
}

void	conditioner(t_params *p)
{
	if (p->x1 < p->x2)
		p->sx = 1;
	else
		p->sx = -1;
	if (p->y1 < p->y2)
		p->sy = 1;
	else
		p->sy = -1;
	if (p->dx > p->dy)
		p->err = p->dx / 2;
	else
		p->err = -p->dy / 2;
}

// draw lines between points in the matrix (map) using Bresenham's line algorithm and my_mlx_pixel_put function
void	draw_line(t_dot **matrix, int rows, int columns, t_data *img, int color)
{
	int			i;
	int			j;
	t_params	p;	
	
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			p.x = matrix[i][j].x;
			p.y = matrix[i][j].y;
			if (j + 1 < columns)
			{
				setter(&p, matrix, i, j + 1);
				conditioner(&p);
				liner(p, img, color);
			}
			if (i + 1 < rows)
			{
				setter(&p, matrix, i + 1, j);
				conditioner(&p);
				liner(p, img, color);
			}
			j++;
		}
		i++;
	}
}
/*
void	put_pixels_matrix(t_dot **matrix, int rows, int columns, t_data *img, int color)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			my_mlx_pixel_put(img, matrix[i][j].x, matrix[i][j].y, color);
			j++;
		}
		i++;
	}
}
*/
void	put_pixel(t_dot **matrix, int rows, int columns)
{
	void	*mlx;
	void	*window;
	int		color;
	t_data	img;
	
	color = 0x00FFFFFF;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.buffer = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//put_pixels_matrix(matrix, rows, columns, &img, color);
	draw_line(matrix, rows, columns, &img, color);
	mlx_put_image_to_window(mlx, window, img.img, 0 , 0);
	free (matrix);
	mlx_loop(mlx);
}