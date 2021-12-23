/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:04:38 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/23 07:30:04 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char	*s, int	*ct2)
{
	int		i;

	i = -1;
	if (!s)
	{
		*ct2 += 6;
		write(1, "(null)", 6);
		return ;
	}
	while (s[++i])
	{
		write(1, &s[i], 1);
		*ct2 += 1;
	}
}
