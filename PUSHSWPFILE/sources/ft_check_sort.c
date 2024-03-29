/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:20:49 by azanane           #+#    #+#             */
/*   Updated: 2022/01/14 15:24:51 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swp.h"

int	ft_check_sort(t_v *v)
{
	int	i;

	v->ct = 0;
	i = 0;
	if (v->ct2 == 0)
	{
		while (++i < v->d)
		{
			if (v->tab[0][i] < v->tab[0][i - 1])
				v->ct++;
		}
		if (v->ct == 0)
			return (1);
	}
	return (0);
}
