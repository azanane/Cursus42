/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 08:40:01 by azanane           #+#    #+#             */
/*   Updated: 2022/02/08 19:06:28 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free_struct(t_philo *p)
{
	free(p);
	return (0);
}

int	philo_is_dead(t_philo *p, t_variables *var, int who, int len)
{
	var->i = -1;
	while (++var->i < len)
		p[var->i].life = 0;
	gettimeofday(&p[who - 1].end, NULL);
	printf("%f %d is dead.\n", getime(&p[who - 1].st, &p[who - 1].end), who);
	return (1);
}

int	ft_join(t_philo *p, t_variables *var, int len)
{
	var->i = -1;
	while (++var->i < len)
		gettimeofday(&p[var->i].last_meal, NULL);
	while (1)
	{
		var->i = -1;
		while (++var->i < len)
		{
			var->time_die = p[var->i].v.time_d;
			gettimeofday(&p[var->i].check, NULL);
			if (getime(&p[var->i].last_meal, &p[var->i].check) >= var->time_die)
				return (philo_is_dead(p, var, var->i + 1, len));
		}
	}
	var->i = -1;
	while (++var->i < len)
	{
		if (pthread_join(p[var->i].pid, NULL) != 0)
			return (ft_free_struct(p));
	}
	return (1);
}

int	ft_thread(t_philo *p, t_variables *var, int len)
{
	while (++var->i < len)
		pthread_mutex_init(&p[var->i].v.mutex, NULL);
	var->i = -1;
	while (++var->i < len && len != 1)
	{
		if (var->i == 0)
			p[var->i].v.mutex_right = p[1].v.mutex;
		else if (var->i == len - 1)
			p[var->i].v.mutex_right = p[0].v.mutex;
		else
			p[var->i].v.mutex_right = p[var->i + 1].v.mutex;
	}
	var->i = -1;
	while (++var->i < len)
	{
		p[var->i].v.which_p = var->i + 1;
		p[var->i].life = 1;
		if (pthread_create(&p[var->i].pid, NULL, &routine, &p[var->i]) != 0)
			return (ft_free_struct(p));
	}
	var->i = -1;
	if (ft_join(p, var, len) == 1)
		ft_free_struct(p);
	return (1);
}
