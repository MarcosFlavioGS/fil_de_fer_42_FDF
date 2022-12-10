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

    // Get number of lines in map file using get_next_line
    fd = open(file, O_RDONLY);
    rows = 0;
    line = get_next_line(fd);
    while (line)
    {
        rows++;
        line = get_next_line(fd);
    }
    close(fd);
    // Get number of columns in map file using ft_count_words
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    columns = ft_count_words(line, ' ');
    close(fd);
    // Allocate memory for matrix
    map = malloc(sizeof(t_dot *) * rows);
    i = 0;
    while (i < rows)
    {
        map[i] = malloc(sizeof(t_dot) * columns);
        i++;
    }
    // Read map into matrix using ft_split and ft_atoi
    fd = open(file, O_RDONLY);
    i = 0;
    while (i < rows)
    {
        line = get_next_line(fd);
        j = 0;
        while (j < columns && line)
        {
            map[i][j].value = ft_atoi(ft_split(line, ' ')[j]);
            j++;
        }
        i++;
    }
    close(fd);
    return (map);
}