#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft/libft.h"
//# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*buffer;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}   t_data;

typedef struct s_dots
{
    int value;
    int x;
    int y;
    int color;
}   t_dot;

void   put_pixel(t_dot **matrix);
t_dot **read_map(char *file);
#endif
