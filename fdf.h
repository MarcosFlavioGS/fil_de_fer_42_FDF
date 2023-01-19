/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:27:27 by mflavio           #+#    #+#             */
/*   Updated: 2023/01/18 22:43:11 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct s_dots
{
	int	value;
	int	x;
	int	y;
}	t_dot;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buffer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_dot	**matrix;
	int		rows;
	int		columns;
}	t_data;

typedef struct s_params
{
	int	i;
	int	j;
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
	int	color;
	int	rows;
	int	columns;
}	t_params;

typedef struct s_read
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;
	int		x;
	int		y;
	int		rows;
	int		columns;
	t_dot	**map;
}	t_read;

struct reader_config {
    int rows_min;
    int columns_min;
    int value;
};

void	put_pixel(t_data data, t_dot **matrix, int rows, int columns);
t_dot	**read_map(char *file, int rows, int columns);
int		get_rows(char *file);
int		get_columns(char *file);
void	isometric(t_dot **matrix, int rows, int columns);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(t_data *vars);
void	mlx_set(t_data *vars);
void	move_to_center(t_dot **map, int rows, int columns, int dist);
int		close_window_esc(int keycode, t_data *vars);
void	ft_error(char *str);
#endif
