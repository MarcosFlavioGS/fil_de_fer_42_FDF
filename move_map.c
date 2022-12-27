/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:58:54 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/27 12:06:51 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map_to_right(t_dot **map, int rows, int columns, int dist)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			map[i][j].x += dist;
			j++;
		}
		i++;
	}
}

void	move_map_to_left(t_dot **map, int rows, int columns, int dist)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			map[i][j].x -= dist;
			j++;
		}
		i++;
	}
}

void	move_map_to_up(t_dot **map, int rows, int columns, int dist)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			map[i][j].y -= dist;
			j++;
		}
		i++;
	}
}

void	move_map_to_down(t_dot **map, int rows, int columns, int dist)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			map[i][j].y += dist;
			j++;
		}
		i++;
	}
}