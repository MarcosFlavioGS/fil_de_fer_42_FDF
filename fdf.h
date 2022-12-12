/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:27:27 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/12 00:59:39 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*buffer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_dots
{
	int	value;
	int	x;
	int	y;
	int	color;
}	t_dot;

void	put_pixel(t_dot **matrix, int rows, int columns);
t_dot	**read_map(char *file, int rows, int columns);
int		get_rows(char *file);
int		get_columns(char *file);
#endif
