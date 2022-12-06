#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->buffer + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    put_pixel(void)
{
    int         color;
	void		*mlx;
	void		*window;
	t_data		img;
	
    color = 0x00FF0000;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.buffer = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, color);
    my_mlx_pixel_put(&img, 10, 5, color);
	mlx_put_image_to_window(mlx, window, img.img, 0 , 0);
	mlx_loop(mlx);
}
