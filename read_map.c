#include "fdf.h"
#include "libft/libft.h"

int ft_count_words(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] != c)
        {
            count++;
            while (str[i] != c && str[i])
                i++;
        }
        else
            i++;
    }
    return (count);
}

void read(char *file, t_dot **map,int rows, int columns)
{
    int fd;
    char *line;
    int i;
    int j;
    int x;
    int y;

    fd = open(file, O_RDONLY);
    i = 0;
    x = 30;
    while (i < rows)
    {
        line = get_next_line(fd);
        j = 0;
        y = 30;
        while (j < columns && line)
        {
            map[i][j].value = ft_atoi(ft_split(line, ' ')[j]);
            map[i][j].x = y;
            map[i][j].y = x;
            if (map[i][j].value != 0)
              map[i][j].color = 0x00FF0000;
            else
              map[i][j].color = 0x00FFFFFF;
            j++;
            y += 15;
        }
        i++;
        x += 15;
    }
    close(fd);
    free(line);
}

t_dot **read_map(char *file)
{
    int fd;
    char *line;
    int columns;
    int rows;
    int i;
    int j;
    t_dot **map;

    rows = get_lines(file);
    columns = get_columns(file);
    // Allocating memory for matrix
    map = malloc(sizeof(t_dot *) * rows);
    i = 0;
    while (i < rows)
    {
        map[i] = malloc(sizeof(t_dot) * columns);
        i++;
    }
    read(file, &map, rows, columns);
    return (map);
}
