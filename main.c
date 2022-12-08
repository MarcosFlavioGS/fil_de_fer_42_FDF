/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:30:38 by mflavio-          #+#    #+#             */
/*   Updated: 2022/12/06 18:44:56 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
/*
int	main(void)
{
    //int **matrix;

    if (argc != 2)
    {
        ft_error("Usage: ./fdf <yourmap.fdf>");
    }
    
    //matrix = read_map(*++argv);
    put_pixel();
}
*/

// ft_count_words function

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

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int **map;
    int columns;
    int rows;
    int i;
    int j;

    // Get number of lines in map file using get_next_line
    fd = open(argv[1], O_RDONLY);
    rows = 0;
    line = get_next_line(fd);
    while (line)
    {
        rows++;
        line = get_next_line(fd);
    }
    close(fd);
    // Get number of columns in map file using ft_count_words
    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    columns = ft_count_words(line, ' ');
    close(fd);
    // Allocate memory for matrix
    map = (int **)malloc(sizeof(int *) * rows);
    i = 0;
    while (i < rows)
    {
        map[i] = (int *)malloc(sizeof(int) * columns);
        i++;
    }
    // Read map into matrix using ft_split and ft_atoi
    fd = open(argv[1], O_RDONLY);
    i = 0;
    while (i < rows)
    {
        line = get_next_line(fd);
        j = 0;
        while (j < columns && line)
        {
            map[i][j] = ft_atoi(ft_split(line, ' ')[j]);
            j++;
        }
        i++;
    }
    close(fd);
    // Print entire matrix
    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < columns)
        {
            ft_printf("%d ", map[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
    return (0);
}
