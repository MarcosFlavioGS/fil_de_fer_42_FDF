#include "fdf.h"

void    isometric(t_dot **matrix)
{
    int i;
    int j;

    i = 0;
    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j].value != 0)
        {
            matrix[i][j].x = (matrix[i][j].x - matrix[i][j].y) * cos(0.523599);
            matrix[i][j].y = (matrix[i][j].x + matrix[i][j].y) * sin(0.523599) - matrix[i][j].value;
            j++;
        }
        i++;
    }
}