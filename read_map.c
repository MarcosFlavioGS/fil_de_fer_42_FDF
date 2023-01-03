/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:54 by mflavio           #+#    #+#             */
/*   Updated: 2023/01/03 19:04:33 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static void	reader(char *file, t_dot **map, t_read read, int dist)
{
	read.fd = open(file, O_RDONLY);
	read.i = 0;
	read.x = 70;
	while (read.i < read.rows)
	{
		read.line = get_next_line(read.fd);
		read.j = 0;
		read.split = ft_split(read.line, ' ');
		free(read.line);
		read.y = 50;
		while (read.j < read.columns)
		{
			map[read.i][read.j].value = ft_atoi(read.split[read.j]);
			free(read.split[read.j]);
			map[read.i][read.j].x = read.y;
			map[read.i][read.j++].y = read.x;
			read.y += dist;
		}
		read.i++;
		read.x += dist;
		free(read.split);
	}
	move_to_center(map, read.rows, read.columns, dist
		*((read.rows + read.columns) / 25));
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
	t_read	read;

	read.rows = rows;
	read.columns = columns;
	read.map = allocation(read.rows, read.columns);
	if (!read.map)
		return (NULL);
	if (rows >= 500 && columns >= 500)
		reader(file, read.map, read, 1);
	if (rows >= 300 && columns >= 300)
		reader(file, read.map, read, 2);
	else if (rows > 150 && columns > 150)
		reader(file, read.map, read, 4);
	else if (rows >= 100 || columns >= 100)
		reader(file, read.map, read, 7);
	else if (rows >= 30 || columns >= 30)
		reader(file, read.map, read, 15);
	else if (rows <= 30 && columns <= 30)
		reader(file, read.map, read, 30);
	return (read.map);
}
