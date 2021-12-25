/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:30:36 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/22 22:34:15 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_hexa(char	*s, int	*ct2)
{
	int		i;
	char	base[16] = "0123456789abcdef";

	i = -1;
	if (!s)
	{
		*ct2 += 6;
		write(1, "(null)", 6);
		return ;
	}
	while (s[++i])
	{
		write(1, &base[s[i] % 16], 1);
		*ct2 += 1;
	}
}