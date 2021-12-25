/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:40:30 by anaszanane        #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/22 23:00:46 by anaszanane       ###   ########.fr       */
=======
/*   Updated: 2021/12/23 08:25:07 by azanane          ###   ########.fr       */
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
void	ft_putnbr_base_neg(int	n, int	b, const char *str, int	*ct2)
=======
void	ft_putnbr_base_neg(int n, int b, char	*base, int	*ct2)
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
{
	char	base[16] = "0123456789abcdef";

	if (n == INT_MIN)
	{
		write(1, "80000000", 8);
		*ct2 += 8;
		return ;
	}
	if (n < 0)
	{
<<<<<<< HEAD
		if (*str != 'p')
			write(1, "f", 1);
=======
		write(1, "f", 1);
		*ct2 += 1;
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
		n = INT_MAX + n + 1;
	}
	if (n % 16 >= 0 && n % 16 <= 16)
	{
<<<<<<< HEAD
		ft_putnbr_base_neg(n / b, b, str, ct2);
		ft_putchar(base[n % b], ct2);
	}
}

void	ft_putnbr_base(int n, int	b, const char	*str, int	*ct2)
=======
		if (n > b - 1)
		{
			ft_putnbr_base_neg(n / b, b, base, ct2);
			ft_putchar(base[n % b], ct2);
		}
	}
}

void	ft_putnbr_base(int n, int b, char	*base, int	*ct2)
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
{
	char	base[16] = "0123456789abcdef";

	if (n < 0)
	{
		ft_putnbr_base_neg(n, b, str, ct2);
		return ;
	}
<<<<<<< HEAD
	if (n > b - 1)
		ft_putnbr_base(n / b, b, str, ct2);
	ft_putchar(base[n % b], ct2);
}
=======
	if (n % 16 >= 0 && n % 16 <= 16)
	{
		if (n > b - 1)
			ft_putnbr_base(n / b, b, base, ct2);
		ft_putchar(base[n % b], ct2);
	}
}
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
