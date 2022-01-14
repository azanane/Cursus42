/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:56:13 by azanane           #+#    #+#             */
/*   Updated: 2022/01/14 15:25:17 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swp.h"

void	ft_radix(t_v *v)
{
	v->ct2 = 0;
	v->i = 0;
	while (ft_check_sort(v) == 0)
	{
		v->n = -1;
		while (++v->n < v->d)
		{
			if ((v->tab[0][0] >> v->i & 1) == 0)
			{
				ft_operation(v, "pb");
				v->ct2++;
			}
			else
				ft_operation(v, "ra");
		}
		v->n = -1;
		v->tmp = v->ct2;
		while (++v->n < v->tmp)
		{
			ft_operation(v, "pa");
			v->ct2--;
		}
		v->i++;
	}
}
