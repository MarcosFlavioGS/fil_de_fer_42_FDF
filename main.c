/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:30:38 by mflavio-          #+#    #+#             */
/*   Updated: 2022/12/06 18:44:56 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static void	printer(t_dot **map, int rows, int columns);

int	main(int argc, char **argv)
{
  int rows;
  int columns;
	t_dot	**matrix;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <yourmap.fdf>");
	}

  rows = get_rows(char *file);
  columns = get_columns(char *file);
	matrix = read_map(*++argv, rows, columns);
	printer(matrix, rows, columns);
	put_pixel(matrix);
}

static void	printer(t_dot **map, rows, columns)
{
	int	i = 0;
	int	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			ft_printf("%d ", map[i][j].value);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
