/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:15:55 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/22 20:22:12 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_sorting(const char	*str, int	*i, va_list	arg, int	*ct2)
{
	int	nb;
	
	if (str[*i + 1] == 'c')
		ft_putchar(va_arg(arg, int), ct2);
	else if (str[*i + 1] == 's')
		ft_putstr(va_arg(arg, char	*), ct2);
	else if (str [*i + 1] == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_base(va_arg(arg, int), 16, "0123456789abcdef", ct2);
	}	
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		ft_putnbr(va_arg(arg, int), ct2);
	else if (str[*i + 1] == 'u')
	{
		nb = va_arg(arg, unsigned int);
		if (nb > 0)
			ft_putnbr(nb, ct2);
	}
	else if (str[*i + 1] == 'x')	
		ft_putnbr_base(va_arg(arg, unsigned int), 16, "0123456789abcdef", ct2);
	else if (str[*i + 1] == '%')
	{
		write(1, "%", 1);
		*ct2 += 1;
	}
}

int	ft_printf(const char	*str, ...)
{
	va_list	arg;
	int	i;
	int	ct;
	int	ct2;

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
			write(1, &str[i],1);
	}
	va_end(arg);
	// if (str[2] == 0 && str[0] == 0)
	// 	return (0);
	return (i - (ct * 2) + ct2);
}

// int	main(void)
// {
// 	// ft_printf("A%cas %c%c\n", 'n', 'a', 'z');
// 	// printf("A%cas %c%c\n\n", 'n', 'a', 'z');
// 	// ft_printf("A%sas %s %s\n", "Nas", "Zanane", "Bg");
// 	// printf("A%sas %s %s\n\n", "Nas", "Zanane", "Bg");
// 	ft_printf("%p %p %p\n", "Nas", "Zanane", "Bg");
// 	printf("%p %p %p\n\n", "Nas", "Zanane", "Bg");
// 	// ft_printf("A%das %u %u  %% %x\n", 8, 10, -10, -10);
// 	// printf("A%das %u %u  %% %x\n\n", 8, 10, -10, -10);
// 	// ft_printf("%x %x %x %x\n", 233, -2000, INT_MIN, INT_MAX);
// 	// printf("%x %x %x %x", 233, -2000, INT_MIN, INT_MAX);
// 	return (0);
// }
