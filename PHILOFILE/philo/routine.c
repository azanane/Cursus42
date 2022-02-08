/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:05:40 by azanane           #+#    #+#             */
/*   Updated: 2022/02/08 18:55:08 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	want_eat(void *arg, t_rout *r)
{
	pthread_mutex_lock(&(*(t_philo *)arg).v.mutex);
	pthread_mutex_lock(&(*(t_philo *)arg).v.mutex_right);
	gettimeofday(&r->end, NULL);
	if ((*(t_philo *)arg).life == 1)
		printf("%f %d has taken a fork.\n", getime(&r->st, &r->end), r->who);
	r->n = -1;
	while (++r->n < (r->eat * 1000))
		usleep(1);
	gettimeofday(&(*(t_philo *)arg).last_meal, NULL);
	r->ct_meals++;
	r->ct_time += r->eat;
	pthread_mutex_unlock(&(*(t_philo *)arg).v.mutex);
	pthread_mutex_unlock(&(*(t_philo *)arg).v.mutex_right);
}

void	routine_start(void *arg, t_rout *r)
{
	want_eat(arg, r);
	if (((*(t_philo *)arg).v.total_v) == 5 && r->ct_meals == r->nb_meals)
		return ;
	gettimeofday(&r->end, NULL);
	if ((*(t_philo *)arg).life == 1)
		printf("%f %d is sleeping.\n", getime(&r->st, &r->end), r->who);
	r->i = -1;
	while (++r->n < (r->sleep * 1000))
		usleep(1);
	gettimeofday(&(*(t_philo *)arg).end, NULL);
	if ((*(t_philo *)arg).life == 1)
		printf("%f %d is thinking.\n", getime(&r->st, &r->end), r->who);
	r->ct_time += r->sleep;
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
	gettimeofday(&(*(t_philo *)arg).st, NULL);
	r->st = (*(t_philo *)arg).st;
}

void	*routine(void *arg)
{
	t_rout	r;

	usleep(r.nb_philo - r.who + 4);
	ft_initialize(arg, &r);
	if ((r.who % 2) == 0)
		usleep(r.eat / 2);
	if (((*(t_philo *)arg).v.total_v) == 5)
	{
		while ((*(t_philo *)arg).life == 1 && r.ct_meals < r.nb_meals)
		{
			routine_start(arg, &r);
			if (r.ct_time >= r.die)
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
			if (r.ct_time >= r.die)
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
	return (arg);
}
