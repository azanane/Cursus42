/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:50:46 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/10 21:33:05 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

void	ft_index(t_v *v)
{
	v->i = -1;
	v->tmp = v->tab[0][0];
	v->tmp3 = v->tab[0][0];
	while (++v->i <= v->d)
	{
		if (v->tmp > v->tab[0][v->i])
		{
			v->tmp = v->tab[0][v->i];
			v->tmp2 = v->i;
		}
		if (v->tmp3 < v->tab[0][v->i])
			v->tmp3 = v->tab[0][v->i];
	}
	v->tmp5 = v->tmp;
	while (v->tmp3 != v->tmp)
	{
		v->tmp5--;
		v->i = v->tmp2;
		v->n = v->tmp2;
		v->tmp6 = v->tmp3 + 1;
		while (v->i != 0 && v->n != v->d - 1)
		{
			if (v->i > 0)
				v->i--;
			if (v->n < v->d - 1)
				v->n++;
			if (v->tab[0][v->i] < v->tab[0][v->n] && v->tab[0][v->i] < v->tmp6 && v->tmp2 != 0)
			{
				v->tmp6 = v->tab[0][v->i];
				v->tmp4 = v->i;
			}
			if (v->tab[0][v->n] < v->tab[0][v->i] && v->tab[0][v->n] < v->tmp6 && v->tmp2 != v->d - 1)
			{
				v->tmp6 = v->tab[0][v->n];
				v->tmp4 = v->n;
			}
		}
		v->tab[0][v->tmp4] = v->tmp5;
		v->i = -1;
		v->tmp3 = v->tab[0][0];
		while (++v->i <= v->d)
		{
			if (v->tmp3 < v->tab[0][v->i])
				v->tmp3 = v->tmp;
		}
		printf("ok\n");
	}
	int	i; 
	
	i = -1;
	while (++i < v->d)
		printf("%d ", v->tab[0][i]);
}
