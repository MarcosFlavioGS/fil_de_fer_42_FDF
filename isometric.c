#include "fdf.h"

void    isometric(t_dot **matrix, int rows, int columns)
{
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < columns)
        {
            matrix[i][j].x = (matrix[i][j].x - matrix[i][j].y) * cos(0.5);
            matrix[i][j].y = (matrix[i][j].x + matrix[i][j].y) * sin(0.5) - matrix[i][j].value;
            matrix[i][j].x += 100;
            matrix[i][j].y += 100;
            j++;
        }
        i++;

    }
}
