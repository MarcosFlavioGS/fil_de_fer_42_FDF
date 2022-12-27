/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:30:38 by mflavio-          #+#    #+#             */
/*   Updated: 2022/12/27 12:29:10 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int		rows;
	int		columns;
	t_dot	**matrix;
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <yourmap.fdf>");
		return (1);
	}

	rows = get_rows(argv[1]);
	columns = get_columns(argv[1]);
	mlx_set(&data);
	matrix = read_map(*++argv, rows, columns);
	isometric(matrix, rows, columns);
	put_pixel(data, matrix, rows, columns);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0 , 0);
	mlx_hook(data.win, 17, 1L<<17, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}