/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:36:03 by mflavio-          #+#    #+#             */
/*   Updated: 2023/02/02 20:04:58 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "libft/libft.h"

t_enum	set_enum_struct(void)
{
	t_enum	enm;

	enm.case_1 = 0.5;
	enm.case_2 = 1;
	enm.case_3 = 2;
	enm.case_4 = 3;
	enm.case_5 = 6;
	enm.case_6 = 15;
	enm.case_7 = 20;
	return (enm);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_enum	enm;

	if (argc != 2)
		ft_error("Error: Usage: ./fdf <filename.fdf>");
	if (check_file_extension(argv[1]) == 0)
		ft_error("Error: Invalid file extension");
	data.rows = get_rows(argv[1]);
	data.columns = get_columns(argv[1]);
	mlx_set(&data);
	enm = set_enum_struct();
	data.matrix = read_map(*++argv, data.rows, data.columns, enm);
	if (!data.matrix || !data.mlx || !data.win || !data.img)
		ft_error("Error: Memory Error");
	parallel(data.matrix, data.rows, data.columns);
	put_pixel(data, data.matrix, data.rows, data.columns);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 1L << 17, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, close_window_esc, &data);
	mlx_loop(data.mlx);
	return (0);
}
