#include "fdf.h"

// Geting number of lines in map
int get_lines(char *file)
{
    int fd;
    char *line;
    int rows;

    fd = open(file, O_RDONLY);
    rows = 0;
    line = get_next_line(fd);
    while (line)
    {
        rows++;
        line = get_next_line(fd);
    }
    close(fd);
    free(line);
    return (rows);
}