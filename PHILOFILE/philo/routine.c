/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:05:40 by azanane           #+#    #+#             */
/*   Updated: 2022/02/02 11:58:59 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dprintf(1, "%ld %d %d %d\n", current_time.tv_sec, eat, die, sleep);

void	want_fork(void *arg, t_rout *r)
{
	int	i;

	pthread_mutex_lock(&(*(t_philo *)arg).mutex_1);
	pass_fork(r, (*(t_philo *)arg).frk, r.who, (*(t_philo *)arg).frk[r.who]);
	pthread_mutex_unlock(&(*(t_philo *)arg).mutex_1);
	if ((*(t_philo *)arg).frk[r.who] == 2)
	{
		write(1, "")
		ft_ptstr("")
		i = -1;
		while (++i < r.eat)
	}
}

void	routine_start(void *arg, t_rout *r)
{
	want_fork(arg, r);
}

void	*routine_initialize(void *arg)
{
	t_rout	r;

	r.who = (*(t_philo *)arg).p;
	r.nb_philo = (*(t_philo *)arg).tb[1];
	r.eat = (*(t_philo *)arg).tb[1];
	r.die = (*(t_philo *)arg).tb[2];
	r.sleep = (*(t_philo *)arg).tb[3];
	if (((*(t_philo *)arg).n) == 5)
		r.nb_meals = (*(t_philo *)arg).tb[4];
	while (1)
	{
		usleep((*(t_philo *)arg).nph + 2);
		gettimeofday(&r.current_time2, NULL);
		routine_start(arg, r);
	}
	return (arg);
}
