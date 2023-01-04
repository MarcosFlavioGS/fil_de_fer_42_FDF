/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:30:38 by mflavio-          #+#    #+#             */
/*   Updated: 2023/01/04 19:30:54 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error("Error: Usage: ./fdf <filename.fdf>");
	data.rows = get_rows(argv[1]);
	data.columns = get_columns(argv[1]);
	mlx_set(&data);
	data.matrix = read_map(*++argv, data.rows, data.columns);
	if (!data.matrix || !data.mlx || !data.win || !data.img)
		ft_error("Error: Memory Error");
	isometric(data.matrix, data.rows, data.columns);
	put_pixel(data, data.matrix, data.rows, data.columns);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 1L << 17, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, close_window_esc, &data);
	mlx_loop(data.mlx);
	return (0);
}
