#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->buffer + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    put_pixel(t_dot **matrix)
{
	void		*mlx;
	void		*window;
	t_data		img;
	int			i;
	int			j;
	
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.buffer = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			my_mlx_pixel_put(&img, matrix[i][j].x, matrix[i][j].y, matrix[i][j].color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, window, img.img, 0 , 0);
	mlx_loop(mlx);
}
