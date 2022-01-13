/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:50:46 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/13 17:13:33 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

int	ft_conv_bin(int n, t_v *v)
{
	int	nb;
	int	n2;
	int	ctn;
	int	ct;

	nb = 1;
	n2 = n;
	while (n > 0)
	{
		ct = 2;
		ctn = 1;
		while (ct != n2 && ct != n2 - 1)
		{
			ct += 2;
			ctn++;
		}
		if (ct == n2)
			nb = nb * 10 + 0;
		else
			nb = nb * 10 + 1;
		n2 = ctn;
		n = ctn / 2;
		v->ct2++;
	}
	if (v->ct2 > v->ct3)
		v->ct3 = v->ct2;
	return (nb);
}

void	ft_index(t_v *v)
{
	v->i = -1;
	v->i = -1;
	v->ct2 = 0;
	while (++v->i < v->d)
	{
		v->n = -1;
		v->ct = 2;
		while (++v->n < v->d)
		{
			if (v->tab[0][v->i] > v->tab[0][v->n])
				v->ct++;
		}
		v->ct2 = 0;
		v->tab[1][v->i] = ft_conv_bin(v->ct, v);
	}
	v->i = -1;
	while (++v->i <= v->d - 1)
		v->tab[0][v->i] = v->tab[1][v->i];
}
