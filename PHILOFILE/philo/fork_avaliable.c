/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_avaliable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:40:22 by azanane           #+#    #+#             */
/*   Updated: 2022/02/04 11:18:05 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_avaliable(void *arg, t_rout *r)
{
	if (r->who == 1)
	{
		if (((*(t_philo *)arg).frk[1]) == 1)
			return (1);
		else if (((*(t_philo *)arg).frk[r->nb_philo - 1]) == 1)
			return (r->nb_philo - 1);
	}
	if (r->who == r->nb_philo)
	{
		if (((*(t_philo *)arg).frk[0]) == 1)
			return (0);
		else if (((*(t_philo *)arg).frk[r->nb_philo - 2]) == 1)
			return (r->nb_philo - 2);
	}
	else
	{
		if (((*(t_philo *)arg).frk[r->who]) == 1)
			return (r->who);
		else if (((*(t_philo *)arg).frk[r->who - 2]) == 1)
			return (r->who - 2);
	}
	return (-1);
}
