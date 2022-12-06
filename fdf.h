#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*buffer;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}   t_data;

void   put_pixel(void);
#endif
