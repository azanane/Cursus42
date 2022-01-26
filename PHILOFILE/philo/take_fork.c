/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:52:16 by azanane           #+#    #+#             */
/*   Updated: 2022/01/26 11:07:59 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_pass(int *tab, int i, int n)
{
	tab[i] += 1;
	tab[n] -= 1;
	return (0);
}

int	giveback_fork(t_val *v, int i)
{
	if (i == 0)
	{
		if (v->frk[v->tab[0] - 1] == 0)
			return (ft_pass(v->frk, v->tab[0] - 1, 0));
		else if (v->frk[1] == 0)
			return (ft_pass(v->frk, 1, 0));
	}
	else if (i == (v->tab[0] - 1))
	{
		if (v->frk[v->tab[0] - 2] == 0)
			return (ft_pass(v->frk, v->tab[0] - 2, v->tab[0] - 1));
		else if (v->frk[1] == 0)
			return (ft_pass(v->frk, 0, v->tab[0] - 1));
	}
	else
	{
		if (v->frk[i - 1] == 0)
			return (ft_pass(v->frk, i - 1, i));
		else if (v->frk[i + 1] == 0)
			return (ft_pass(v->frk, i + 1, i));
	}
	return (1);
}

int	pass_fork(t_val *v, int i, int nb)
{
	if (nb == 2)
		return (giveback_fork(v, i));
	else if (i == 0)
	{
		if (v->frk[v->tab[0] - 1] == 1)
			return (ft_pass(v->frk, 0, v->tab[0] - 1));
		else if (v->frk[1] == 1)
			return (ft_pass(v->frk, 0, 1));
	}
	else if (i == (v->tab[0] - 1))
	{
		if (v->frk[v->tab[0] - 2] == 1)
			return (ft_pass(v->frk, v->tab[0] - 1, v->tab[0] - 2));
		else if (v->frk[1] == 1)
			return (ft_pass(v->frk, v->tab[0] - 1, 0));
	}
	else
	{
		if (v->frk[i - 1] == 1)
			return (ft_pass(v->frk, i, i - 1));
		else if (v->frk[i + 1] == 1)
			return (ft_pass(v->frk, i, i + 1));
	}
	return (1);
}
