/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:02:36 by mflavio           #+#    #+#             */
/*   Updated: 2023/01/10 17:13:43 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_dot **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	close_window(t_data *vars)
{
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free (vars->mlx);
	free_matrix(vars->matrix, vars->rows);
	exit(0);
}

int	close_window_esc(int keycode, t_data *vars)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free (vars->mlx);
		free_matrix(vars->matrix, vars->rows);
		exit(0);
	}
	return (0);
}
