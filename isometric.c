/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:15:18 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/23 20:20:35 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    isometric(t_dot **matrix, int rows, int columns)
{
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < columns)
        {
            matrix[i][j].x = (matrix[i][j].x - matrix[i][j].y) * cos(0.5);
            matrix[i][j].y = (matrix[i][j].x + matrix[i][j].y) * sin(0.4) - matrix[i][j].value;
            matrix[i][j].x += 600;
            matrix[i][j].y += 200;
            j++;
        }
        i++;

    }
}
