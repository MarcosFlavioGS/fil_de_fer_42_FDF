/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:30:38 by mflavio-          #+#    #+#             */
/*   Updated: 2023/01/04 17:13:08 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int		rows;
	int		columns;
	t_data	data;

	if (argc != 2)
		ft_error("Error: Usage: ./fdf <filename.fdf>");
	rows = get_rows(argv[1]);
	columns = get_columns(argv[1]);
	mlx_set(&data);
	data.matrix = read_map(*++argv, rows, columns);
	if (!data.matrix || !data.mlx || !data.win || !data.img)
		return (1);
	isometric(data.matrix, rows, columns);
	put_pixel(data, data.matrix, rows, columns);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 1L << 17, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, close_window_esc, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free (data.mlx);
	return (0);
}
