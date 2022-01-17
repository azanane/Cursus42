/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:15:55 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/15 16:19:08 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		*ct2 += 2;
		n = va_arg(arg, unsigned long long);
		ft_putadd(n, "0123456789abcdef", ct2);
	}
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		ft_putnbr(va_arg(arg, int), ct2);
	else if (str[*i + 1] == 'u')
	{
		nb = va_arg(arg, int);
		ft_putunbr(nb, ct2);
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
