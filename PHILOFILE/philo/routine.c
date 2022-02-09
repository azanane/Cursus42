/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:05:40 by azanane           #+#    #+#             */
/*   Updated: 2022/02/09 15:28:09 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	want_eat(void *arg, t_rout *r)
{
	pthread_mutex_lock((*(t_philo *)arg).v.mutex);
	gettimeofday(&r->end, NULL);
	if ((*(t_philo *)arg).life == 1)
		printf("%.0f %d has taken a fork.\n", gtime(&r->st, &r->end), r->who);
	pthread_mutex_lock((*(t_philo *)arg).v.mutex_right);
	gettimeofday(&r->end, NULL);
	if ((*(t_philo *)arg).life == 1)
		printf("%.0f %d has taken a fork.\n", gtime(&r->st, &r->end), r->who);
	gettimeofday(&r->end, NULL);
	if ((*(t_philo *)arg).life == 1)
		printf("%.0f %d is eating.\n", gtime(&r->st, &r->end), r->who);
	gettimeofday(&(*(t_philo *)arg).last_meal, NULL);
	usleep(r->eat * 1000);
	r->ct_meals++;
	pthread_mutex_unlock((*(t_philo *)arg).v.mutex);
	pthread_mutex_unlock((*(t_philo *)arg).v.mutex_right);
}

void	routine_start(void *arg, t_rout *r)
{
	if (r->nb_philo != 1)
	{
		want_eat(arg, r);
		if ((((*(t_philo *)arg).v.total_v) == 5 && r->ct_meals < r->nb_meals)
			|| ((*(t_philo *)arg).v.total_v) == 4)
		{
			gettimeofday(&r->end, NULL);
			if ((*(t_philo *)arg).life == 1)
			{
				printf("%.0f %d is sleeping.\n", gtime(&r->st, &r->end), r->who);
				usleep(r->sleep * 1000);
			}
			gettimeofday(&(*(t_philo *)arg).end, NULL);
			if ((*(t_philo *)arg).life == 1)
				printf("%.0f %d is thinking.\n", gtime(&r->st, &r->end), r->who);
		}
		else
			(*(t_philo *)arg).life = 0;
	}
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
	gettimeofday(&(*(t_philo *)arg).st, NULL);
	gettimeofday(&r->end, NULL);
	r->st = (*(t_philo *)arg).st;
	if ((*(t_philo *)arg).life == 1 && r->nb_philo == 1)
		printf("%.0f %d has taken a fork.\n", gtime(&r->st, &r->end), r->who);
}

void	*routine(void *arg)
{
	t_rout	r;

	ft_initialize(arg, &r);
	if (r.nb_philo == 1)
	{
		usleep(r.die * 1000);
		gettimeofday(&r.end, NULL);
		if ((*(t_philo *)arg).life == 1)
			printf("%.0f %d is dead.\n", gtime(&r.st, &r.end), r.who);
		(*(t_philo *)arg).life = 0;
	}
	if ((r.who % 2) == 0)
		usleep(r.eat / 2);
	if (((*(t_philo *)arg).v.total_v) == 5)
	{
		while ((*(t_philo *)arg).life == 1 && r.ct_meals < r.nb_meals)
			routine_start(arg, &r);
	}
	else
	{
		while ((*(t_philo *)arg).life == 1)
			routine_start(arg, &r);
	}
	return (arg);
}
