#include "fdf.h"

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