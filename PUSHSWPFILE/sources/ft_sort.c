/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:38:29 by azanane           #+#    #+#             */
/*   Updated: 2022/01/14 16:43:19 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swp.h"

void	ft_sort_2(t_v *v)
{
	if (v->tab[0][0] == 0)
	{
		ft_operation(v, "sa");
		ft_operation(v, "ra");
	}
	else if (v->tab[0][2] == 0 && v->tab[0][0] == 1)
		ft_operation(v, "rra");
	else if (v->tab[0][2] == 0)
	{
		ft_operation(v, "sa");
		ft_operation(v, "rra");
	}
	else if (v->tab[0][1] == 0 && v->tab[0][0] == 1)
		ft_operation(v, "sa");
	else
	{
		ft_operation(v, "rra");
		ft_operation(v, "rra");
	}
}

void	ft_sort(t_v *v)
{
	if (v->d == 2)
		ft_operation(v, "sa");
	else if (v->d == 3)
		ft_sort_2(v);
	else
	{
		while (v->tab[0][0] != 0)
			ft_operation(v, "ra");
		ft_operation(v, "pb");
		while (v->tab[0][2] != 3)
			ft_operation(v, "ra");
		if (v->tab[0][0] > v->tab[0][1])
			ft_operation(v, "sa");
		v->ct2 = 1;
		ft_operation(v, "pa");
	}
}
