/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wireframe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:13:00 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/07 15:26:16 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_3(t_algo *a, int xm, int ym)
{
	double	dltx;
	double	dlty;
	int		pxls;
	double	pxlx;
	double	pxly;

	dltx = (a->dx1 - a->dx);
	dlty = (a->dy1 - a->dy);
	pxls = sqrt((dltx * dltx) + (dlty * dlty));
	dltx /= pxls;
	dlty /= pxls;
	pxlx = a->dx + (960 - (xm / 2));
	pxly = a->dy + (540 - (ym / 2));
	a->cl3 = (a->cl1 - a->cl2) / pxls;
	while (pxls > 0)
	{
		mlx_pixel_put(a->ptr, a->win, pxlx, pxly, a->cl1 + a->cl3);
		pxlx += dltx;
		pxly += dlty;
		pxls--;
	}
}

void	ft_trace_2(int **tab, int ym, int xm, t_algo *a)
{
	if (a->x < xm - 1)
	{
		a->dy = (a->y - tab[a->y][a->x] + a->x) * a->c / 2;
		a->dy1 = (a->y - tab[a->y][a->x + 1] + a->x + 1) * a->c / 2;
		a->dx = (a->x - a->y) * a->c;
		a->dx1 = ((a->x + 1) - a->y) * a->c;
		a->cl1 = a->col[a->y][a->x];
		a->cl2 = a->col[a->y][a->x + 1];
		ft_trace_3(a, xm, ym);
	}
	if (a->y < ym - 1)
	{
		a->dy = (a->y - tab[a->y][a->x] + a->x) * a->c / 2;
		a->dy1 = ((a->y + 1) - tab[a->y + 1][a->x] + a->x) * a->c / 2;
		a->dx = (a->x - a->y) * a->c;
		a->dx1 = (a->x - (a->y + 1)) * a->c;
		a->cl1 = a->col[a->y][a->x];
		a->cl2 = a->col[a->y + 1][a->x];
		ft_trace_3(a, xm, ym);
	}
}

void	ft_trace(int **tab, int ym, int xm, t_algo *a)
{
	a->y = -1;
	a->win = mlx_new_window(a->ptr, 1920, 1080, "azanane fdf");
	if (!a->win)
	{
		ft_free_int(tab, ym);
		exit (1);
	}
	while (++(a->y) < ym)
	{
		a->x = -1;
		while (++(a->x) < xm)
			ft_trace_2(tab, ym, xm, a);
	}
	xm = 0;
	while (xm < ym)
	{
		free(a->col[xm]);
		a->col[xm] = NULL;
		xm++;
	}
	free(a->col);
}

void	ft_wireframe(int **tab, int ym, int xm, t_algo *a)
{
	a->c = xm * ym;
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
	else if (a->c > 20)
		a->c = a->c / 10;
	else
		a->c = a->c / 0.5;
	ft_put_col(a, xm, ym);
	ft_freee(a->file);
	ft_trace(tab, ym, xm, a);
	ft_free_int(tab, ym);
}
