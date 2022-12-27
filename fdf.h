/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio <mflavio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:27:27 by mflavio           #+#    #+#             */
/*   Updated: 2022/12/27 17:09:30 by mflavio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

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
}	t_read;

void	put_pixel(t_data data, t_dot **matrix, int rows, int columns);
t_dot	**read_map(char *file, int rows, int columns);
int		get_rows(char *file);
int		get_columns(char *file);
void	isometric(t_dot **matrix, int rows, int columns);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(t_data *vars);
void	mlx_set(t_data *vars);
void	move_map_to_right(t_dot **matrix, int rows, int columns, int dist);
int		close_window_esc(int keycode, t_data *vars);
#endif
