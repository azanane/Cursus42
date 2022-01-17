/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 08:33:18 by azanane           #+#    #+#             */
/*   Updated: 2022/01/15 16:19:08 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunbrbase(unsigned int n, unsigned int b, char	*base, int	*ct2)
{
	if (n % 16 >= 0 && n % 16 <= 16)
	{
		if (n > b - 1)
			ft_putnbr_base(n / b, b, base, ct2);
		ft_putchar(base[n % b], ct2);
	}
}
