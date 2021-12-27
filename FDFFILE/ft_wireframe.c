/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wireframe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:13:00 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/27 18:35:38 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_2(t_algo	*a)
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
	pixelx = a->dx + 960;
	pixely = a->dy + 540;
	while (pixels)
	{
		mlx_pixel_put(a->ptr, a->win, pixelx, pixely, 0xFFFFFF);
		pixelx += deltax;
		pixely += deltay;
		pixels--;
	}
}

void	ft_trace(int	**tab, int ymax, int xmax, t_algo *a)
{
	double	c;

	a->y = 0;
	a->win = mlx_new_window(a->ptr, 1920, 1080, "azanane fdf");
	c = xmax * ymax;
	if (c > 500)
		c = 6;
	c = 20;
	while (a->y < ymax)
	{
		a->x = 0;
		while (a->x < xmax)
		{
			if (a->x < xmax - 1)
			{
				a->dy = (a->y * c - tab[a->y][a->x] + a->x * c) / 2;
				a->dy1 = (a->y * c - tab[a->y][a->x + 1] + (a->x + 1) * c) / 2;
				a->dx = a->x * c - a->y * c;
				a->dx1 = (a->x + 1) * c - a->y * c;
				ft_trace_2(a);
			}
			if (a->y < ymax - 1)
			{
				a->dy = (a->y * c - tab[a->y][a->x] + a->x * c) / 2;
				a->dy1 = ((a->y + 1) * c - tab[a->y + 1][a->x] + a->x * c) / 2;
				a->dx = a->x * c - a->y * c;
				a->dx1 = a->x * c - (a->y + 1) * c;
				ft_trace_2(a);
			}
			a->x++;
		}
		a->y++;
	}
}

void	ft_wireframe(int	**tab, int ymax, int xmax, t_algo *a)
{
	t_v		v;

	ft_trace(tab, ymax, xmax, a);
	v.n = 0;
	while (v.n < ymax)
	{
		free(tab[v.n]);
		tab[v.n] = NULL;
		v.n++;
	}
	// free(tab);
}
