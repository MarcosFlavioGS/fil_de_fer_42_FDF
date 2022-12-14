/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:31:54 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/12 00:45:32 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static void	reader(char *file, t_dot **map,int rows, int columns)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	int		x;
	int		y;
	
	fd = open(file, O_RDONLY);
	i = 0;
	x = 50;
	while (i < rows)
	{
		line = get_next_line(fd);
		j = 0;
		y = 50;
		while (j < columns && line)
		{
			map[i][j].value = ft_atoi(ft_split(line, ' ')[j]);
			map[i][j].x = y;
			map[i][j].y = x;
			if (map[i][j].value != 0)
				map[i][j].color = 0x00FF0000;
			else
				map[i][j].color = 0x00FFFFFF;
			j++;
			y += 5;
		}
		i++;
		x += 5;
	}
	close(fd);
	free(line);
}

t_dot	**read_map(char *file, int rows, int columns)
{
	int		i;
	t_dot	**map;
	
	map = malloc(sizeof(t_dot *) * rows);
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(sizeof(t_dot) * columns);
		i++;
	}
	reader(file, map, rows, columns);
	return (map);
}
