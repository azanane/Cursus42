/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:15:55 by anaszanane        #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/22 23:02:52 by anaszanane       ###   ########.fr       */
=======
/*   Updated: 2021/12/23 10:22:22 by azanane          ###   ########.fr       */
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_sorting2(const char	*str, int	*i, va_list	arg, int	*ct2)
{
	if (str[*i + 1] == 'x')
		ft_putunbrbase(va_arg(arg, unsigned int), 16, "0123456789abcdef", ct2);
	else if (str[*i + 1] == 'X')
		ft_putunbrbase(va_arg(arg, unsigned int), 16, "0123456789ABCDEF", ct2);
	else if (str[*i + 1] == '%')
	{
		write(1, "%", 1);
		*ct2 += 1;
	}
}

void	ft_conv_sorting(const char	*str, int	*i, va_list	arg, int	*ct2)
{
	unsigned int		nb;
	unsigned long long	n;

	if (str[*i + 1] == 'c')
		ft_putchar(va_arg(arg, int), ct2);
	else if (str[*i + 1] == 's')
		ft_putstr(va_arg(arg, char *), ct2);
	else if (str [*i + 1] == 'p')
	{
		write(1, "0x", 2);
<<<<<<< HEAD
		nb = va_arg(arg, int);
		if (nb < 0)
		ft_putnbr_base(nb, 16, &str[*i + 1], ct2);
		// ft_putstr_hexa(va_arg(arg, char	*), ct2);
	}	
=======
		*ct2 += 2;
		n = va_arg(arg, unsigned long long);
		ft_putadd(n, "0123456789abcdef", ct2);
	}
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		ft_putnbr(va_arg(arg, int), ct2);
	else if (str[*i + 1] == 'u')
	{
<<<<<<< HEAD
		nb = va_arg(arg, unsigned int);
		if (nb > 0)
			ft_putnbr(nb, ct2);
	}
	else if (str[*i + 1] == 'x')	
		ft_putnbr_base(va_arg(arg, unsigned int), 16, &str[*i + 1], ct2);
	else if (str[*i + 1] == '%')
	{
		write(1, "%", 1);
		*ct2 += 1;
=======
		nb = va_arg(arg, int);
		ft_putunbr(nb, ct2);
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
	}
	else
		ft_conv_sorting2(str, i, arg, ct2);
}

int	ft_printf(const char	*str, ...)
{
	va_list	arg;
	int		i;
	int		ct;
	int		ct2;

	i = -1;
	ct = 0;
	ct2 = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_conv_sorting(str, &i, arg, &ct2);
			i++;
			ct++;
		}
		else
			write(1, &str[i], 1);
	}
	va_end(arg);
	return (i - (ct * 2) + ct2);
}
<<<<<<< HEAD

int	main(void)
{
	char	*bg;
	
	// ft_printf("A%cas %c%c\n", 'n', 'a', 'z');
	// printf("A%cas %c%c\n\n", 'n', 'a', 'z');
	// ft_printf("A%sas %s %s\n", "Nas", "Zanane", "Bg");
	// printf("A%sas %s %s\n\n", "Nas", "Zanane", "Bg");
	ft_printf("%p %p %p\n", &bg, "Zanane", "Bg");
	printf("%p %p %p\n\n", &bg, "Zanane", "Bg");
	// ft_printf("A%das %u %u  %% %x\n", 8, 10, -10, -10);
	// printf("A%das %u %u  %% %x\n\n", 8, 10, -10, -10);
	// ft_printf("%x %x %x %x\n", 233, -2000, INT_MIN, INT_MAX);
	// printf("%x %x %x %x", 233, -2000, INT_MIN, INT_MAX);
	return (0);
}
=======
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
