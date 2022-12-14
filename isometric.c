#include "fdf.h"

void    isometric(t_dot **matrix)
{
    int     i;
    int     j;
    int     x;
    int     y;
    int     z;

    i = 0;
    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j].x != -1)
        {
            x = matrix[i][j].x;
            y = matrix[i][j].y;
            z = matrix[i][j].value;
            matrix[i][j].x = (x - y) * cos(0.523599);
            matrix[i][j].y = -z + (x + y) * sin(0.523599);
            j++;
        }
        i++;
    }
}