/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:19:14 by mflavio-          #+#    #+#             */
/*   Updated: 2023/02/01 19:42:01 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel(t_dot **matrix, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			matrix[i][j].x = matrix[i][j].x - matrix[i][j].value * sin(0.5);
			matrix[i][j].y = matrix[i][j].y - matrix[i][j].value * cos(0.5);
			matrix[i][j].x += 500;
			matrix[i][j].y += 400;
			j++;
		}
		i++;
	}
}
