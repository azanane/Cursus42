/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock_unlock_all.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:46:03 by azanane           #+#    #+#             */
/*   Updated: 2022/02/04 11:51:54 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_unlock_all(void *arg, t_rout *r)
{
	r->i = -1;
	while (++r->i < r->nb_philo)
	{
		if (r->i != r->who)
			pthread_mutex_unlock(&(*(t_philo *)arg).v.mutex_tab[r->i]);
	}
}

void	mutex_lock_all(void *arg, t_rout *r)
{
	r->i = -1;
	while (++r->i < r->nb_philo)
	{
		if (r->i != r->who)
			pthread_mutex_lock(&(*(t_philo *)arg).v.mutex_tab[r->i]);
	}
}
