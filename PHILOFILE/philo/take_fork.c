/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:52:16 by azanane           #+#    #+#             */
/*   Updated: 2022/02/01 18:34:09 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_pass(int *tab, int i, int n)
{
	tab[i] += 1;
	tab[n] -= 1;
	return (0);
}

int	giveback_fork(t_val *v, t_philo *p, int i)
{
	if (i == 0)
	{
		if (p->frk[v->tab[0] - 1] == 0)
			return (ft_pass(p->frk, v->tab[0] - 1, 0));
		else if (p->frk[1] == 0)
			return (ft_pass(p->frk, 1, 0));
	}
	else if (i == (v->tab[0] - 1))
	{
		if (p->frk[v->tab[0] - 2] == 0)
			return (ft_pass(p->frk, v->tab[0] - 2, v->tab[0] - 1));
		else if (p->frk[1] == 0)
			return (ft_pass(p->frk, 0, v->tab[0] - 1));
	}
	else
	{
		if (p->frk[i - 1] == 0)
			return (ft_pass(p->frk, i - 1, i));
		else if (p->frk[i + 1] == 0)
			return (ft_pass(p->frk, i + 1, i));
	}
	return (1);
}

int	pass_fork(t_val *v, t_philo *p, int i, int nb)
{
	if (nb == 2)
		return (giveback_fork(v, p, i));
	else if (i == 0)
	{
		if (p->frk[v->tab[0] - 1] == 1)
			return (ft_pass(p->frk, 0, v->tab[0] - 1));
		else if (p->frk[1] == 1)
			return (ft_pass(p->frk, 0, 1));
	}
	else if (i == (v->tab[0] - 1))
	{
		if (p->frk[v->tab[0] - 2] == 1)
			return (ft_pass(p->frk, v->tab[0] - 1, v->tab[0] - 2));
		else if (p->frk[1] == 1)
			return (ft_pass(p->frk, v->tab[0] - 1, 0));
	}
	else
	{
		if (p->frk[i - 1] == 1)
			return (ft_pass(p->frk, i, i - 1));
		else if (p->frk[i + 1] == 1)
			return (ft_pass(p->frk, i, i + 1));
	}
	return (1);
}
