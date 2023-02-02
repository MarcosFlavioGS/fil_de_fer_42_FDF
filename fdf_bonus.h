/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:34:07 by mflavio-          #+#    #+#             */
/*   Updated: 2023/02/02 20:07:45 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_enum
{
	float	case_1;
	float	case_2;
	float	case_3;
	float	case_4;
	float	case_5;
	float	case_6;
	float	case_7;
}	t_enum;

typedef struct s_dots
{
	int	value;
	int	x;
	int	y;
	int	color;
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
	int	rows;
	int	columns;
}	t_params;

typedef struct s_read
{
	int		fd;
	char	*line;
	char	**split;
	char	**hex;
	int		i;
	int		j;
	float	x;
	float	y;
	int		rows;
	int		columns;
	t_dot	**map;
}	t_read;

void	put_pixel(t_data data, t_dot **matrix, int rows, int columns);
t_dot	**read_map(char *file, int rows, int columns, t_enum dst);
int		get_rows(char *file);
int		get_columns(char *file);
void	parallel(t_dot **matrix, int rows, int columns);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(t_data *vars);
void	mlx_set(t_data *vars);
void	move_to_center(t_dot **map, int rows, int columns, int dist);
int		close_window_esc(int keycode, t_data *vars);
void	ft_error(char *str);
int		check_file_extension(char *file);
#endif