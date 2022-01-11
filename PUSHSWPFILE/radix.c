/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:56:13 by azanane           #+#    #+#             */
/*   Updated: 2022/01/11 17:57:52 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

int	ft_check(t_v *v)
{
	int	i;

	i = -1;
	v->ct = 0;
	while (++i <= v->i)
	{
		if ((v->tab[0][0] >> v->i) & (1 == 0))
			v->ct++;
	}
	if (v->ct > 0)
		return (1);
	return (0);
}

void	ft_radix(t_v *v)
{
	v->i = 0;
	v->ct2 = 0;
	while (ft_check_sort(v) == 0)
	{
		if ((v->tab[0][0] >> v->i) & (1 == 0))
		{
			ft_operation(v, "pb");
			v->ct2++;
		}
		else if (((v->tab[0][0] >> v->i) & (1 == 1)) && ft_check(v) == 1)
			ft_operation(v, "ra");
		else if (((v->tab[0][0] >> v->i) & (1 == 1)) && ft_check(v) == 0)
		{
			v->n = -1;
			while (++v->n < v->ct2)
				ft_operation(v, "pa");
			v->i++;
			v->ct2 = 0;
		}
	}
	int r = -1;

	while (++r < v->d)
		printf("%d ", v->tab[0][r]);
	ft_kill_malloc_int(v->tab, 2);
}
