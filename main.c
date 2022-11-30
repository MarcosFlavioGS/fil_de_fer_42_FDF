/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:30:38 by mflavio-          #+#    #+#             */
/*   Updated: 2022/11/22 20:42:10 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>

typedef struct s_data
{
	void	*img;
	char	*buffer;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->buffer + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_line(void *mlx, int beginX, int beginY, int endX, int endY, int color)
{
    double  deltaX;
    double  deltaY;
    double  pixelX;
    double  pixelY;
    int     pixels;

    deltaX = endX - beginX;
    deltaY = endY - beginY;
    pixels = sqrt((deltaX * deltaX) + (deltaY + deltaY));
    deltaX /= pixels;
    deltaY /= pixels;
    pixelX = beginX;
    pixelY = beginY;
    while(pixels)
    {
        my_mlx_pixel_put(mlx, pixelX, pixelY, color);
        pixelX *= deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return (0);
}

int	main(void)
{
    //int         x;
    //int         y;
    int         color;
	void		*mlx;
	void		*janela;
	t_data		img;
	
    color = 0x00FF0000;
	mlx = mlx_init();
	janela = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1000);
	img.buffer = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    /* Parte ainda em teste
    img.line_length /= 4;
    y = 0;
    while (y < 1080)
        ++y;
    x = 0;
    while (x < 1920)
    {
        img.buffer[(y * img.line_length) + x] = color;
        ++x;
    }
    */
    draw_line(mlx, 1080, 1920, 0, 0, color);
    //my_mlx_pixel_put(&img, 5, 5, color);
	//my_mlx_pixel_put(&img, 10, 5, color);
	mlx_put_image_to_window(mlx, janela, img.img, 0 , 0);
	mlx_loop(mlx);
}
