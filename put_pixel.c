/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:39 by mflavio           #+#    #+#             */
/*   Updated: 2023/01/03 15:24:19 by mflavio-         ###   ########.fr       */
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

void	liner(t_params p, t_data *img)
{
	while (1)
	{
		my_mlx_pixel_put(img, p.x1, p.y1, p.color);
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

void	checker(t_params p, t_dot **matrix, t_data *img)
{
	if (p.j + 1 < p.columns)
	{
		setter(&p, matrix, p.i, p.j + 1);
		conditioner(&p);
		liner(p, img);
	}
	if (p.i + 1 < p.rows)
	{
		setter(&p, matrix, p.i + 1, p.j);
		conditioner(&p);
		liner(p, img);
	}
}

void	put_pixel(t_data data, t_dot **matrix, int rows, int columns)
{
	t_params	p;

	p.color = 0x00FF00;
	p.rows = rows;
	p.columns = columns;
	p.i = 0;
	while (p.i < p.rows)
	{
		p.j = 0;
		while (p.j < p.columns)
		{
			p.x = matrix[p.i][p.j].x;
			p.y = matrix[p.i][p.j].y;
			checker(p, matrix, &data);
			p.j++;
		}
		p.i++;
	}
}
