/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:03:54 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/15 16:19:08 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int	*ct2)
{
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		*ct2 += 11;
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		*ct2 += 1;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, ct2);
	ft_putchar(n % 10 + '0', ct2);
}
