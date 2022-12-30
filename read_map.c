/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:54 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/28 14:11:15 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static void	reader(char *file, t_dot **map,int rows, int columns, int dist)
{
	t_read	read;
	
	read.fd = open(file, O_RDONLY);
	read.i = 0;
	read.x = 70;
	while (read.i < rows)
	{
		read.line = get_next_line(read.fd);
		read.j = 0;
		read.split = ft_split(read.line, ' ');
		free(read.line);
		read.y = 50;
		while (read.j < columns)
		{
			map[read.i][read.j].value = ft_atoi(read.split[read.j]);
			free(read.split[read.j]);
			map[read.i][read.j].x = read.y += dist;
			map[read.i][read.j].y = read.x;
			read.j++;
		}
		read.i++;
		read.x += dist;
		free(read.split);
	}
	close(read.fd);
}

t_dot	**allocation(int rows, int columns)
{
	int		i;
	t_dot	**map;

	map = (t_dot **)malloc(sizeof(t_dot *) * rows);
	i = 0;
	while (i < rows)
	{
		map[i] = (t_dot *)malloc(sizeof(t_dot) * columns);
		i++;
	}
	if (!map)
		return (NULL);
	return (map);
}

t_dot	**read_map(char *file, int rows, int columns)
{
	t_dot	**map;

	map = allocation(rows, columns);
	if (!map)
		return (NULL);
	if (rows < 30 || columns < 30)
		reader(file, map, rows, columns, 30);
	else if ((rows > 30 && rows < 100) || (columns > 30 && columns < 100))
	{
		reader(file, map, rows, columns, 15);
		move_to_center(map, rows, columns, 20);
	}
  else if ((rows > 100 && rows < 300) || (columns > 100 && columns < 300))
	{
		reader(file, map, rows, columns, 7);
		move_to_center(map, rows, columns, 50);
	}
	else if (rows > 300 || columns > 300)
	{
		reader(file, map, rows, columns, 2);
		move_to_center(map, rows, columns, 150);
	}
	return (map);
}
