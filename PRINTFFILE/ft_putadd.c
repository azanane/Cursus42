/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:21:59 by azanane           #+#    #+#             */
/*   Updated: 2021/12/23 10:13:02 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadd(unsigned long long n, char	*base, int	*ct2)
{
	char	addr[16];
	int		i;

	i = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		*ct2 += 1;
	}
	while (n > 0)
	{
		addr[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &addr[i], 1);
		*ct2 += 1;
	}
}
