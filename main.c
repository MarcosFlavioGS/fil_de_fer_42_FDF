/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:30:38 by mflavio-          #+#    #+#             */
/*   Updated: 2022/12/20 19:36:03 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int		rows;
	int		columns;
	t_dot	**matrix;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <yourmap.fdf>");
	}

	rows = get_rows(argv[1]);
	columns = get_columns(argv[1]);
	matrix = read_map(*++argv, rows, columns);
	isometric(matrix, rows, columns);
	put_pixel(matrix, rows, columns);
	free (matrix);
	return (0);
}