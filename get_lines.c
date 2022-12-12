/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:27:39 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/12 00:29:06 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rows(char *file)
{
	int		fd;
	char	*line;
	int		rows;
	
	fd = open(file, O_RDONLY);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (rows);
}