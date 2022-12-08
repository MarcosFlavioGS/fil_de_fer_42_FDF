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
    int i;
    int j;
    int k;

    // Get number of lines and columns in map file using ft_count_words
    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        i++;
        line = get_next_line(fd);
    }
    close(fd);
    // Get number of columns in map file using ft_count_words
    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    j = 0;
    while (line)
    {
        j = ft_count_words(line, ' ');
        line = get_next_line(fd);
    }
    close(fd);
    
    // Allocate memory for matrix
    
    map = (int **)malloc(sizeof(int *) * i);

    k = 0;
    while (k < i)
    {
        map[k] = (int *)malloc(sizeof(int) * j);
        k++;
    }
    // Read map into matrix
    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        j = 0;
        while (j < ft_count_words(line, ' '))
        {
            map[i][j] = ft_atoi(line);
            line = line + ft_count_words(line, ' ');
            j++;
        }
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    // Print matrix using ft_printf
    i = 0;
    j = 0;
    while (i < 10)
    {
        while (j < 10)
        {
            ft_printf("%d ", map[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
    return (0);
}