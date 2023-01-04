/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_columns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:26:52 by mflavio           #+#    #+#             */
/*   Updated: 2023/01/04 19:36:52 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
			i++;
		}
		else
			i++;
	}
	return (count);
}

int	get_columns(char *file)
{
	int		fd;
	char	*line;
	int		columns;
	
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	columns = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (columns);
}
