/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 08:40:01 by azanane           #+#    #+#             */
/*   Updated: 2022/02/03 19:56:18 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free_struct(t_philo *p, t_variables *var, int len)
{
	var->i = -1;
	while (++var->i < len)
		free(p[var->i].frk);
	free(p);
	return (0);
}

int	ft_join(t_philo *p, t_variables *var, int len)
{
	while (++var->i < len)
	{
		if (pthread_join(p[var->i].pid, NULL) != 0)
			return (ft_free_struct(p, var, len));
		if (p[var->i].life == 0)
		{
			var->n = -1;
			while (++var->n < len)
				p[var->i].life = 0;
			pthread_mutex_destroy(&p[var->n].v.mutex);
			var->i = len;
		}
	}
	return (1);
}

int	ft_thread(t_philo *p, t_variables *var, int len)
{
	while (++var->i < len)
	{
		p[var->i].v.which_p = var->i + 1;
		p[var->i].frk = malloc(sizeof(int) * len);
		if (!p[var->i].frk)
			return (ft_free_struct(p, var, var->i));
		var->n = -1;
		while (++var->n < len)
			p[var->i].frk[var->n] = 1;
		p[var->i].life = 1;
		pthread_mutex_init(&p[var->i].v.mutex, NULL);
		if (pthread_create(&p[var->i].pid, NULL, &routine, &p[var->i]) != 0)
			return (ft_free_struct(p, var, var->i));
	}
	var->i = -1;
	if (ft_join(p, var, len) == 1)
		ft_free_struct(p, var, len);
	return (1);
}
