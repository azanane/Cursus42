/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_col.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 07:48:58 by azanane           #+#    #+#             */
/*   Updated: 2022/01/06 08:42:31 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_freee(char	**tab)
{
	int	j;

	j = -1;
	while (tab[++j])
	{
		free(tab[j]);
		tab[j] = NULL;
	}
	free(tab);
	return (NULL);
}

int	ft_free_int(int **tab, int max)
{
	int	i;

	i = -1;
	while (++i < max)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	return (0);
}

void	ft_put_col_2(t_v *v, t_algo *a, int xmax)
{
	while (a->file[v->j][++(v->n)] && ++v->d < xmax)
	{
		while (a->file[v->j][v->n] && ft_isdigit(a->file[v->j][v->n]) == 0)
			v->n++;
		while (a->file[v->j][v->n] && ft_isdigit(a->file[v->j][v->n]) == 1)
			v->n++;
		if (a->file[v->j][v->n] == ',')
		{
			a->col[v->x][v->d] = ft_b(a->file[v->j] + v->n, "0123456789ABCDEF");
			v->n += 8;
		}
		else
			a->col[v->x][v->d] = 0xFFFFFFF;
	}
}

void	ft_put_col(t_algo *a, int xmax, int ymax)
{
	t_v		v;

	a->col = malloc(sizeof(int *) * (ymax));
	if (!a->col)
		return ;
	v.x = -1;
	v.j = -1;
	while (a->file[++(v.j)] && ++v.x < ymax)
	{
		v.n = -1;
		a->col[v.x] = malloc(sizeof(int) * (xmax));
		if (!a->col[v.x])
			return ;
		v.d = -1;
		ft_put_col_2(&v, a, xmax);
	}
}
