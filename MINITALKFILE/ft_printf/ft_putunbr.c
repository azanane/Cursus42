/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 08:03:18 by azanane           #+#    #+#             */
/*   Updated: 2022/01/15 16:19:08 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunbr(unsigned int n, int	*ct2)
{
	if (n % 10 >= 0 && n % 10 <= 9)
	{
		if (n > 9)
			ft_putnbr(n / 10, ct2);
		ft_putchar(n % 10 + '0', ct2);
	}
}
