/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:36:39 by azanane           #+#    #+#             */
/*   Updated: 2022/01/10 21:21:32 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(int **tab, const char *str, int *n)
{
	int			i;
	int			ct;
	long long	nb;

	i = 0;
	ct = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ct = ct * -1;
		i++;
		*n += 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
		*n += 1;
	}
	*n -= 1;
	nb = nb * ct;
	if (nb > INT_MAX || nb < INT_MIN)
	{
		ft_kill_malloc_int(tab, 2);
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (nb);
}
