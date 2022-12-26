/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:39 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/26 17:53:28 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	checker(t_params p, t_dot **matrix, int rows, int columns, t_data *img, int color)
{
	if (p.j + 1 < columns)
	{
		setter(&p, matrix, p.i, p.j + 1);
		conditioner(&p);
		liner(p, img, color);
	}
	if (p.i + 1 < rows)
	{
		setter(&p, matrix, p.i + 1, p.j);
		conditioner(&p);
		liner(p, img, color);
	}
}

void	draw_line(t_dot **matrix, int rows, int columns, t_data *img, int color)
{
	t_params	p;	
	
	p.i = 0;
	while (p.i < rows)
	{
		p.j = 0;
		while (p.j < columns)
		{
			p.x = matrix[p.i][p.j].x;
			p.y = matrix[p.i][p.j].y;
			checker(p, matrix, rows, columns, img, color);
			p.j++;
		}
		p.i++;
	}
}

void	put_pixel(t_dot **matrix, int rows, int columns)
{
	int		color;
	t_data	data;

	color = 0x00FFFFFF;
	mlx_set(&data);
	draw_line(matrix, rows, columns, &data, color);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0 , 0);
	mlx_hook(data.win, 17, 1L<<17, close_window, &data);
	free(matrix);
	mlx_loop(data.mlx);
	free(data.buffer);
}