/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wireframe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:13:00 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/06 11:34:45 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_3(t_algo *a, int xmax, int ymax)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = (a->dx1 - a->dx);
	deltay = (a->dy1 - a->dy);
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = a->dx + (960 - (xmax / 2));
	pixely = a->dy + (540 - (ymax / 2));
	a->col3 = (a->col1 - a->col2) / pixels;
	while (pixels > 0)
	{
		mlx_pixel_put(a->ptr, a->win, pixelx, pixely, a->col1 + a->col3);
		pixelx += deltax;
		pixely += deltay;
		pixels--;
	}
}

void	ft_trace_2(int **tab, int ymax, int xmax, t_algo *a)
{
	if (a->x < xmax - 1)
	{
		a->dy = (a->y - tab[a->y][a->x] + a->x) * a->c / 2;
		a->dy1 = (a->y - tab[a->y][a->x + 1] + a->x + 1) * a->c / 2;
		a->dx = (a->x - a->y) * a->c;
		a->dx1 = ((a->x + 1) - a->y) * a->c;
		a->col1 = a->col[a->y][a->x];
		a->col2 = a->col[a->y][a->x + 1];
		ft_trace_3(a, xmax, ymax);
	}
	if (a->y < ymax - 1)
	{
		a->dy = (a->y - tab[a->y][a->x] + a->x) * a->c / 2;
		a->dy1 = ((a->y + 1) - tab[a->y + 1][a->x] + a->x) * a->c / 2;
		a->dx = (a->x - a->y) * a->c;
		a->dx1 = (a->x - (a->y + 1)) * a->c;
		a->col1 = a->col[a->y][a->x];
		a->col2 = a->col[a->y + 1][a->x];
		ft_trace_3(a, xmax, ymax);
	}
}

void	ft_trace(int **tab, int ymax, int xmax, t_algo *a)
{
	a->y = -1;
	a->win = mlx_new_window(a->ptr, 1920, 1080, "azanane fdf");
	while (++(a->y) < ymax)
	{
		a->x = -1;
		while (++(a->x) < xmax)
			ft_trace_2(tab, ymax, xmax, a);
	}
	xmax = 0;
	while (xmax < ymax)
	{
		free(a->col[xmax]);
		a->col[xmax] = NULL;
		xmax++;
	}
	free(a->col);
}

void	ft_wireframe(int **tab, int ymax, int xmax, t_algo *a)
{
	a->c = xmax * ymax;
	if (a->c > 2000000)
		a->c = 0.00001;
	else if (a->c > 100000)
		a->c = 1.2;
	else if (a->c > 1000)
		a->c = 4;
	else if (a->c > 500)
		a->c = 3;
	else if (a->c > 350)
		a->c = a->c / 30;
	else
		a->c = a->c / 10;
	ft_put_col(a, xmax, ymax);
	ft_freee(a->file);
	ft_trace(tab, ymax, xmax, a);
	ft_free_int(tab, ymax);
}
