/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:54 by mflavio-          #+#    #+#             */
/*   Updated: 2023/02/06 18:49:11 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static int	base(char *str, int base)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr * base + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			nbr = nbr * base + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			nbr = nbr * base + str[i] - 'a' + 10;
		i++;
	}
	return (nbr * sign);
}

static void	set(t_dot *map, int value, int color, t_read *r)
{
	map->x = r->y;
	map->y = r->x;
	map->value = value;
	map->color = color;
	free (r->split[r->j]);
	if (r->hex[1])
		free (r->hex[1]);
	free (r->hex[0]);
	free (r->hex);
}

static void	reader(char *file, t_dot **map, t_read r, float dist)
{
	r.fd = open(file, O_RDONLY);
	r.i = 0;
	r.x = 0;
	while (r.i < r.rows)
	{
		r.line = get_next_line(r.fd);
		r.j = 0;
		r.split = ft_split(r.line, ' ');
		r.y = 0;
		while (r.j < r.columns)
		{
			r.hex = ft_split(r.split[r.j], ',');
			if (r.hex[1])
				set(&map[r.i][r.j], ft_atoi(r.hex[0]), base(r.hex[1], 16), &r);
			else
				set(&map[r.i][r.j], ft_atoi(r.split[r.j]), 0xFFFFFF, &r);
			r.y += dist;
			r.j++;
		}
		r.i++;
		r.x += dist;
		free (r.line);
		free(r.split);
	}
	close(r.fd);
}

t_dot	**allocation(int rows, int columns)
{
	int		i;
	t_dot	**map;

	map = (t_dot **)malloc(sizeof(t_dot *) * rows);
	if (!map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map[i] = (t_dot *)malloc(sizeof(t_dot) * columns);
		if (!map[i])
			return (NULL);
		i++;
	}
	if (!map)
		return (NULL);
	return (map);
}

t_dot	**read_map(char *file, int rows, int columns, t_enum dst)
{
	t_read	read;

	read.rows = rows;
	read.columns = columns;
	read.map = allocation(read.rows, read.columns);
	if (!read.map)
		return (NULL);
	if (rows >= 1000 || columns >= 1000)
		reader(file, read.map, read, dst.case_1);
	else if (rows >= 500 || columns >= 500)
		reader(file, read.map, read, dst.case_2);
	else if (rows >= 300 || columns >= 300)
		reader(file, read.map, read, dst.case_3);
	else if (rows > 150 && columns > 150)
		reader(file, read.map, read, dst.case_4);
	else if (rows >= 100 || columns >= 100)
		reader(file, read.map, read, dst.case_5);
	else if (rows >= 30 || columns >= 30)
		reader(file, read.map, read, dst.case_6);
	else if (rows <= 30 && columns <= 30)
		reader(file, read.map, read, dst.case_7);
	move_to_center(read.map, rows, columns, (rows + columns) / 4);
	return (read.map);
}
