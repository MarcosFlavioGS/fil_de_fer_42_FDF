/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:39 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/25 01:10:38 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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