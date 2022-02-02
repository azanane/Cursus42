/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:52:16 by azanane           #+#    #+#             */
/*   Updated: 2022/02/02 17:43:23 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_pass(int *tab, int i, int n)
{
	tab[i] += 1;
	tab[n] -= 1;
	return (0);
}

int	giveback_fork(t_rout *r, int *frk, int i)
{
	if (i == 0)
	{
		if (frk[r->nb_philo - 1] == 0)
			return (ft_pass(frk, r->nb_philo - 1, 0));
		else if (frk[1] == 0)
			return (ft_pass(frk, 1, 0));
	}
	else if (i == (r->nb_philo - 1))
	{
		if (frk[r->nb_philo - 2] == 0)
			return (ft_pass(frk, r->nb_philo - 2, r->nb_philo - 1));
		else if (frk[1] == 0)
			return (ft_pass(frk, 0, r->nb_philo - 1));
	}
	else
	{
		if (frk[i - 1] == 0)
			return (ft_pass(frk, i - 1, i));
		else if (frk[i + 1] == 0)
			return (ft_pass(frk, i + 1, i));
	}
	return (1);
}

int	p_fork(t_rout *r, int *frk, int i, int nb)
{
	if (nb == 2)
		return (giveback_fork(r, frk, i));
	else if (i == 0)
	{
		if (frk[r->nb_philo - 1] == 1)
			return (ft_pass(frk, 0, r->nb_philo - 1));
		else if (frk[1] == 1)
			return (ft_pass(frk, 0, 1));
	}
	else if (i == (r->nb_philo - 1))
	{
		if (frk[r->nb_philo - 2] == 1)
			return (ft_pass(frk, r->nb_philo - 1, r->nb_philo - 2));
		else if (frk[1] == 1)
			return (ft_pass(frk, r->nb_philo - 1, 0));
	}
	else
	{
		if (frk[i - 1] == 1)
			return (ft_pass(frk, i, i - 1));
		else if (frk[i + 1] == 1)
			return (ft_pass(frk, i, i + 1));
	}
	return (1);
}
