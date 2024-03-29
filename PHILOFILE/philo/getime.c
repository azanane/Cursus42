/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:10:15 by azanane           #+#    #+#             */
/*   Updated: 2022/02/09 13:44:18 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float	gtime(struct timeval *st, struct timeval *end)
{
	return (((end->tv_sec - st->tv_sec) + 1e-6
			* (end->tv_usec - st->tv_usec)) * 1000);
}
