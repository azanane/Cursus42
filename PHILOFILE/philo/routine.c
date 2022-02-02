/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:05:40 by azanane           #+#    #+#             */
/*   Updated: 2022/02/02 19:42:40 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dprintf(1, "%ld %d %d %d\n", current_time.tv_sec, eat, die, sleep);

void	want_fork(void *arg, t_rout *r)
{
	int	i;

	pthread_mutex_lock(&(*(t_philo *)arg).mutex_1);
	// p_fork(r, (*(t_philo *)arg).frk, r->who, (*(t_philo *)arg).frk[r->who]);
	pthread_mutex_unlock(&(*(t_philo *)arg).mutex_1);
	if ((*(t_philo *)arg).frk[r->who] == 2)
	{
		gettimeofday(&r->current_time2, NULL);
		ft_putnbr_fd((r->current_time2.tv_sec - r->current_time.tv_sec), 1);
		ft_pstr(" ", 1);
		ft_putnbr_fd(r->who, 1);
		ft_pstr(" has taken a fork.\n", 1);
		i = -1;
		while (++i < r->eat)
			usleep(1);
		p_fork(r, (*(t_philo *)arg).frk, r->who, (*(t_philo *)arg).frk[r->who]);
		r->ct_meals++;
	}
}

void	routine_start(void *arg, t_rout *r)
{
	want_fork(arg, r);
	// or_think(arg, r);
	want_fork(arg, r);
	// or_sleep(arg, r);
	want_fork(arg, r);
}

void	*routine(void *arg)
{
	t_rout	r;

	r.who = (*(t_philo *)arg).p;
	r.nb_philo = (*(t_philo *)arg).tb[1];
	r.eat = (*(t_philo *)arg).tb[1];
	r.die = (*(t_philo *)arg).tb[2];
	r.sleep = (*(t_philo *)arg).tb[3];
	if (((*(t_philo *)arg).n) == 5)
		r.nb_meals = (*(t_philo *)arg).tb[4];
	r.ct_meals = 0;
	gettimeofday(&r.current_time, NULL);
	while (1)
	{
		r.tmp = r.ct_meals;
		usleep((*(t_philo *)arg).nph + 2);
		// routine_start(arg, &r);
		if (r.tmp == r.ct_meals)
		{
			ft_putnbr_fd((r.current_time.tv_sec - r.current_time2.tv_sec), 1);
			ft_pstr(" ", 1);
			ft_putnbr_fd(r.who, 1);
			ft_pstr(" died.\n", 1);
			break ;
		}
	}
	return (arg);
}
