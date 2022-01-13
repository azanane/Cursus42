/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:56:13 by azanane           #+#    #+#             */
/*   Updated: 2022/01/13 18:58:27 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

int	ft_power(int n)
{
	int	nb;

	nb = 1;
	while (n > 0)
	{
		nb = nb * 10;
		n--;
	}
	return (nb);
}

int	ft_check(t_v *v)
{
	int	i;
	int	max;

	i = -1;
	max = v->d - v->ct2;
	v->ct = 0;
	while (++i < max)
	{
		if ((v->tab[0][i] / v->i % 10) == 1)
			v->ct++;
	}
	if (v->ct > 0)
		return (1);
	return (0);
}

void	ft_radix(t_v *v)
{
	v->ct2 = 0;
	v->i = 1;
	v->ct3 = ft_power(v->ct3);
	while (v->i != v->ct3)
	{
		if ((v->tab[0][0] / v->i % 10) == 1 && v->d - v->ct2 > 0)
		{
			ft_operation(v, "pb");
			v->ct2++;
		}
		else if (((v->tab[0][0] / v->i % 10) == 0) && ft_check(v) > 0)
			ft_operation(v, "ra");
		else if (ft_check(v) == 0 && v->ct2 > 0)
		{
			v->n = -1;
			v->tmp = v->ct2;
			while (++v->n < v->tmp)
			{
				ft_operation(v, "pa");
				v->ct2--;
			}
			v->i *= 10;
		}
		else if (ft_check(v) == 0 && v->ct2 == 0)
			v->i *= 10;
	}
	int r = -1;
	while (++r < v->d - v->ct2)
		dprintf(1, "%d ", v->tab[0][r]);
	dprintf(1, "\n");
	printf("\n%d", ft_check_sort(v));
	ft_kill_malloc_int(v->tab, 2);
}
