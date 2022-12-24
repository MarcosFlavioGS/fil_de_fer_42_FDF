/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:27:27 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/23 21:45:19 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

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
}	t_dot;

typedef struct s_params
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_params;

void	put_pixel(t_dot **matrix, int rows, int columns);
t_dot	**read_map(char *file, int rows, int columns);
int		get_rows(char *file);
int		get_columns(char *file);
void	isometric(t_dot **matrix, int rows, int columns);
#endif
