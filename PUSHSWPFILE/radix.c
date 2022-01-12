/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:56:13 by azanane           #+#    #+#             */
/*   Updated: 2022/01/12 16:23:06 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

int	ft_check(t_v *v)
{
	int	i;
	int	max;

	i = -1;
	max = v->d - v->ct2;
	v->ct = 0;
	while (++i < max)
	{
		if ((v->tab[0][i] >> v->i & 1) == 0)
			v->ct++;
	}
	if (v->ct > 0)
		return (1);
	return (0);
}

void	ft_radix(t_v *v)
{
	v->i = 1;
	v->ct2 = 0;
	int r = -1;
	while (++r < v->d - v->ct2)
		printf("%d ", v->tab[0][r]);
	printf("\n");
	while (/*ft_check_sort(v) == 0*/v->i <= 5)
	{
		if ((v->tab[0][0] >> v->i & 1) == 0 && v->d - v->ct2 > 0)
		{
			ft_operation(v, "pb");
			v->ct2++;
		}
		else if (((v->tab[0][0] >> v->i & 1) == 1) && ft_check(v) == 1)
			ft_operation(v, "ra");
		else if (v->d - v->ct2 == 0 || (((v->tab[0][0] >> v->i & 1) == 1)
			&& ft_check(v) == 0 && v->ct2 > 0))
		{
			v->n = -1;
			v->tmp = v->ct2;
			while (++v->n < v->tmp)
			{
				ft_operation(v, "pa");
				v->ct2--;
			}
			v->i++;
			v->ct2 = 0;
		}
		int r = -1;
		while (++r < v->d - v->ct2)
			printf("%d ", v->tab[0][r]);
		printf("\n");
	}
	ft_kill_malloc_int(v->tab, 2);
}
