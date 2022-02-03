/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:05:40 by azanane           #+#    #+#             */
/*   Updated: 2022/02/03 21:05:55 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	want_fork(void *arg, t_rout *r)
{
	r->who = 1;
	pthread_mutex_lock(&(*(t_philo *)arg).v.mutex);
	dprintf(1, "ok\n");
	pthread_mutex_unlock(&(*(t_philo *)arg).v.mutex);
	return (1);
}

void	routine_start(void *arg, t_rout *r)
{
	int	tmp;

	tmp = 1;
	if (r->who % 2 == 0)
	{
		while (tmp == 1)
			tmp = want_fork(arg, r);
	}
	// or_think(arg, r);
	// want_fork(arg, r);
	// or_sleep(arg, r);
	// want_fork(arg, r);
}

void	ft_initialize(void *arg, t_rout *r)
{
	r->who = (*(t_philo *)arg).v.which_p;
	r->nb_philo = (*(t_philo *)arg).v.total_p;
	r->eat = (*(t_philo *)arg).v.time_e;
	r->sleep = (*(t_philo *)arg).v.time_s;
	r->die = (*(t_philo *)arg).v.time_d;
	if (((*(t_philo *)arg).v.total_v) == 5)
		r->nb_meals = (*(t_philo *)arg).v.total_m;
	r->ct_meals = 0;
}

void	*routine(void *arg)
{
	t_rout	r;

	ft_initialize(arg, &r);
	if (((*(t_philo *)arg).v.total_v) == 5)
	{
		while ((*(t_philo *)arg).life == 1 || r.ct_meals < r.nb_meals)
		{
			r.tmp = r.ct_meals;
			usleep((r.nb_philo * 3.4) - r.who);
			routine_start(arg, &r);
			break ;
		}
	}
	else
	{
		while ((*(t_philo *)arg).life == 1)
		{
			ft_initialize(arg, &r);
			r.tmp = r.ct_meals;
			usleep(r.nb_philo - r.who + 2);
			routine_start(arg, &r);
		}
	}
	return (arg);
}
