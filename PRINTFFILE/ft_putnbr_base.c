/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:40:30 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/23 08:25:07 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_neg(int n, int b, char	*base, int	*ct2)
{
	if (n == INT_MIN)
	{
		write(1, "80000000", 8);
		*ct2 += 8;
		return ;
	}
	if (n < 0)
	{
		write(1, "f", 1);
		*ct2 += 1;
		n = INT_MAX + n + 1;
	}
	if (n % 16 >= 0 && n % 16 <= 16)
	{
		if (n > b - 1)
		{
			ft_putnbr_base_neg(n / b, b, base, ct2);
			ft_putchar(base[n % b], ct2);
		}
	}
}

void	ft_putnbr_base(int n, int b, char	*base, int	*ct2)
{
	if (n < 0)
	{
		ft_putnbr_base_neg(n, b, base, ct2);
		return ;
	}
	if (n % 16 >= 0 && n % 16 <= 16)
	{
		if (n > b - 1)
			ft_putnbr_base(n / b, b, base, ct2);
		ft_putchar(base[n % b], ct2);
	}
}
