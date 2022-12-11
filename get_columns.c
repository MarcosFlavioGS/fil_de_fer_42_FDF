#include "fdf.h"

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

// Get number of columns in map
int get_columns(char *file)
{
    int fd;
    char *line;
    int columns;

    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    columns = ft_count_words(line, ' ');
    close(fd);
    free(line);
    return (columns);
}