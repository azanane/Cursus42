/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:05:40 by azanane           #+#    #+#             */
/*   Updated: 2022/02/04 13:45:29 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	want_eat(void *arg, t_rout *r)
{
	int	which_one;

	which_one = fork_avaliable(arg, r);
	if (which_one != -1)
	{
		pthread_mutex_lock(&(*(t_philo *)arg).v.mutex_tab[which_one]);
		(*(t_philo *)arg).frk[which_one] = 0;
		(*(t_philo *)arg).frk[r->who - 1] = 2;
		gettimeofday(&(*(t_philo *)arg).current_time2, NULL);
		r->time = (*(t_philo *)arg).current_time2.tv_usec;
		r->time = r->time - (*(t_philo *)arg).current_time.tv_usec;
		printf("%d %d has taken a fork.\n", r->time, r->who);
		r->n = -1;
		while (++r->n < r->eat)
			usleep(1);
		(*(t_philo *)arg).frk[which_one] = 1;
		(*(t_philo *)arg).frk[r->who - 1] = 1;
		r->ct_meals++;
		r->ct_time += r->eat;
		pthread_mutex_unlock(&(*(t_philo *)arg).v.mutex_tab[which_one]);
	}
}

void	routine_start(void *arg, t_rout *r)
{
	if (r->who % 2 == 0)
		want_eat(arg, r);
	gettimeofday(&(*(t_philo *)arg).current_time2, NULL);
	r->time = (*(t_philo *)arg).current_time2.tv_usec;
	r->time = r->time - (*(t_philo *)arg).current_time.tv_usec;
	printf("%d %d is thinking.\n", r->time, r->who);
	want_eat(arg, r);
	gettimeofday(&(*(t_philo *)arg).current_time2, NULL);
	r->time = (*(t_philo *)arg).current_time2.tv_usec;
	r->time = r->time - (*(t_philo *)arg).current_time.tv_usec;
	printf("%d %d is sleeping.\n", r->time, r->who);
	r->i = -1;
	while (++r->n < r->sleep)
		usleep(1);
	r->ct_time += r->sleep;
	want_eat(arg, r);
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
	r->tmp = 0;
	r->ct_time = 0;
}

void	*routine(void *arg)
{
	t_rout	r;

	ft_initialize(arg, &r);
	usleep(r.nb_philo - r.who + 4);
	gettimeofday(&(*(t_philo *)arg).current_time, NULL);
	if (((*(t_philo *)arg).v.total_v) == 5)
	{
		while ((*(t_philo *)arg).life == 1 && r.ct_meals < r.nb_meals)
		{
			routine_start(arg, &r);
			if (r.ct_time == r.die)
			{
				if (r.ct_meals == r.tmp)
					(*(t_philo *)arg).life = 0;
				else
				{
					r.tmp = r.ct_meals;
					r.ct_time = 0;
				}
			}
		}
	}
	else
	{
		while ((*(t_philo *)arg).life == 1)
		{
			routine_start(arg, &r);
			if (r.ct_time == r.die)
			{
				if (r.ct_meals == r.tmp)
				{
					(*(t_philo *)arg).life = 0;
					exit (1);
				}
				else
				{
					r.tmp = r.ct_meals;
					r.ct_time = 0;
				}
			}
		}
	}
	return (arg);
}
