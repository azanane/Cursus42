/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wireframe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:18:13 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/25 08:11:07 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace(int	**tab, int	ymax, int	xmax, void	*ptr)
{
	t_algo	v;

	v.y = 4;
	v.win = mlx_new_window(v.ptr, xmax + 10, ymax + 10, "azanane fdf");
	while (++v.y - 5 < ymax)
	{
		v.x = 4;
		while (++v.x - 5 < xmax)
		{
			v.dx = v.x;
			v.dy = v.y + tab[v.dy - 5][v.x - 5];
			mlx_pixel_put(ptr, v.win, v.dx, v.dy, (int)4);
			v.dx = v.x + 1;
			v.dy = v.y + 1 + tab[v.dy - 5][v.x - 4];
			mlx_pixel_put(ptr, v.win, v.dx, v.dy, (int)4);
		}
	}
}

void	ft_wireframe(int	**tab, int	ymax, int	xmax)
{
	t_algo	a;
	t_v		v;

	a.ptr = mlx_init();
	if (a.ptr == 0)
		return ;
	ft_trace(tab, ymax, xmax, a.ptr);
	v.n = -1;
	while (tab[++v.n])
	{
		free(tab[v.n]);
		tab[v.n] = NULL;
	}
	free(tab);
}