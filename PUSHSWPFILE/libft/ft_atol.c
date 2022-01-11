/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:36:39 by azanane           #+#    #+#             */
/*   Updated: 2022/01/11 16:13:36 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_err(int **tab)
{
	ft_kill_malloc_int(tab, 2);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

long long	ft_atol(int **tab, const char *str, int *n)
{
	int			i;
	int			ct;
	long long	nb;

	i = 0;
	ct = 1;
	nb = 0;
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
		ft_err(tab);
	return (nb);
}
