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

t_dot **read_map(char *file)
{
    int fd;
    char *line;
    int columns;
    int rows;
    int i;
    int j;
    t_dot **map;

    // Geting number of lines in map
    fd = open(file, O_RDONLY);
    rows = 0;
    line = get_next_line(fd);
    while (line)
    {
        rows++;
        line = get_next_line(fd);
    }
    close(fd);
    // Get number of columns in map
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    columns = ft_count_words(line, ' ');
    close(fd);
    // Allocating memory for matrix
    map = malloc(sizeof(t_dot *) * rows);
    i = 0;
    while (i < rows)
    {
        map[i] = malloc(sizeof(t_dot) * columns);
        i++;
    }
    // Reading map into matrix and returning
    fd = open(file, O_RDONLY);
    i = 0;
    while (i < rows)
    {
        line = get_next_line(fd);
        j = 0;
        while (j < columns && line)
        {
            map[i][j].value = ft_atoi(ft_split(line, ' ')[j]);
            map[i][j].x = j + 5;
            map[i][j].y = i + 5;
            map[i][j].color = 0x00FFFFFF;
            j++;
        }
        i++;
    }
    close(fd);
    return (map);
}