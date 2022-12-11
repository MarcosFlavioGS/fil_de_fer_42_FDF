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

static void printer(t_dot **map);

int	main(int argc, char **argv)
{
    t_dot **matrix;

    if (argc != 2)
    {
        ft_printf("Usage: ./fdf <yourmap.fdf>");
    }
    
    matrix = read_map(*++argv);
    printer(matrix);
    put_pixel(matrix);
}

static void printer(t_dot **map)
{
    // Print entire matrix
    int i = 0;
    int j = 0;
    while (i < 11)
    {
        j = 0;
        while (j < 19)
        {
            ft_printf("%d ", map[i][j].value);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}
