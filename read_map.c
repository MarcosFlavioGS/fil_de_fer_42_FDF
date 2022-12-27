/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:54 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/26 23:19:12 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static void	reader(char *file, t_dot **map,int rows, int columns, int dist)
{
	t_read	read;
	
	read.fd = open(file, O_RDONLY);
	read.i = 0;
	read.x = 80;
	while (read.i < rows)
	{
		read.line = get_next_line(read.fd);
		read.j = 0;
		read.y = 50;
		read.split = ft_split(read.line, ' ');
		free(read.line);
		while (read.j < columns)
		{
			map[read.i][read.j].value = ft_atoi(read.split[read.j]);
			free(read.split[read.j]);
			map[read.i][read.j].x = read.y += dist;
			map[read.i][read.j++].y = read.x;
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
	return (map);
}

t_dot	**read_map(char *file, int rows, int columns)
{
	t_dot	**map;
	
	map = allocation(rows, columns);
  	if (rows > 100 || columns > 100)
		reader(file, map, rows, columns, 6);
	else
		reader(file, map, rows, columns, 20);
	return (map);
}
