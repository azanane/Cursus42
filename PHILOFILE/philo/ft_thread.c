/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 08:40:01 by azanane           #+#    #+#             */
/*   Updated: 2022/02/01 19:50:18 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	int	eat;
	int	die;
	int	sleep;

	eat = (*(t_philo *)arg).toeat;
	die = (*(t_philo *)arg).todie;
	sleep = (*(t_philo *)arg).tosleep;
	while (1)
	{
		usleep((*(t_philo *)arg).nph);
	}
	return (arg);
}

int	ft_thread(t_val *v)
{
	t_philo	philo[v->tab[0]];

	while (++v->i < v->tab[0])
	{
		philo[v->i].toeat = v->tab[1];
		philo[v->i].todie = v->tab[2];
		philo[v->i].tosleep = v->tab[3];
		philo[v->i].nph = v->tab[0] - v->i;
		if (pthread_create(&philo[v->i].philoid, NULL, &routine, &philo[v->i]) != 0)
			return (0);
	}
	return (1);
}
