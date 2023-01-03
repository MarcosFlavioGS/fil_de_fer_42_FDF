/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:37:18 by mflavio           #+#    #+#             */
/*   Updated: 2023/01/03 15:28:19 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_dot **matrix, int i, int j, int zoom)
{
	matrix[i][j].x *= zoom;
	matrix[i][j].y *= zoom;
}

void	zoom_out(t_dot **matrix, int i, int j, int zoom)
{
	matrix[i][j].x /= zoom;
	matrix[i][j].y /= zoom;
}

void	zoomer(t_dot **matrix, int rows, int columns, int zoom)
{
	if (zoom > 0)
		zoom_in(matrix, rows, columns, zoom);
	else
		zoom_out(matrix, rows, columns, zoom);
}
