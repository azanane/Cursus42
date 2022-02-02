/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 08:40:01 by azanane           #+#    #+#             */
/*   Updated: 2022/02/02 11:43:47 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thread(t_val *v, int len)
{
	t_philo	p[len];

	pthread_mutex_init(&v->mutex, NULL);
	while (++v->i < v->tab[0])
	{
		p[v->i].n = -1;
		p[v->i].tb = malloc(sizeof(int) * v->ct);
		p->frk = malloc(sizeof(int) * v->tab[0]);
		while (++(p[v->i].n) < v->tab[0])
			p[v->i].tb[p[v->i].n] = 1;
		p[v->i].n = -1;
		while (++(p[v->i].n) < v->ct)
			p[v->i].tb[p[v->i].n] = v->tab[p[v->i].n];
		gettimeofday(&p[v->i].current_time, NULL);
		p[v->i].p = v->i;
		p[v->i].mutex_1 = v->mutex;
		if (pthread_create(&p[v->i].pid, NULL, &routine, &p[v->i]) != 0)
			return (0);
	}
	pthread_mutex_destroy(&v->mutex);
	free(v->tab);
	return (1);
}
