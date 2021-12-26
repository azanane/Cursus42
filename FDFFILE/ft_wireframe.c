/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wireframe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:18:13 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/26 19:14:02 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_3(void	*ptr, t_algo	v)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = (v.x - v.x) + 50;
	deltay = (v.dy1 - v.dy) + 50;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = v.x + 860;
	pixely = v.dy + 590;
	while (pixels)
	{
		mlx_pixel_put(ptr, v.win, pixelx, pixely, 0xFFFFFF);
		pixelx += deltax + 10;
		pixely += deltay + 10;
		pixels--;
	}
}

void	ft_trace_2(void	*ptr, t_algo	v)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = (v.x + 1 - v.x) + 50;
	deltay = (v.dy1 - v.dy) + 50;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = v.x + 860;
	pixely = v.dy + 590;
	while (pixels)
	{
		mlx_pixel_put(ptr, v.win, pixelx, pixely, 0xFFFFFF);
		pixelx += deltax + 10;
		pixely += deltay + 10;
		pixels--;
	}
}

void	ft_trace(int	**tab, int ymax, int xmax, void	*ptr)
{
	t_algo	v;

	v.y = 0;
	v.win = mlx_new_window(ptr, 1920, 1080, "azanane fdf");
	while (v.y < ymax)
	{
		v.x = 0;
		while (v.x < xmax)
		{
			if (v.x != xmax - 1)
			{
				v.dy = v.y - tab[v.y][v.x];
				v.dy1 = v.y - tab[v.y][v.x + 1];
				ft_trace_2(ptr, v);
			}
			if (v.y != ymax - 1)
			{
				v.dy = v.y - tab[v.y][v.x];
				v.dy1 = v.y + 1 - tab[v.y + 1][v.x];
				ft_trace_3(ptr, v);
			}
			v.x++;
		}
		v.y++;
	}
}

void	ft_wireframe(int	**tab, int ymax, int xmax)
{
	t_algo	a;
	t_v		v;

	a.ptr = mlx_init();
	if (a.ptr == 0)
		return ;
	ft_trace(tab, ymax, xmax, a.ptr);
	v.n = 0;
	while (v.n < ymax)
	{
		free(tab[v.n]);
		tab[v.n] = NULL;
		v.n++;
	}
	free(tab);
}
