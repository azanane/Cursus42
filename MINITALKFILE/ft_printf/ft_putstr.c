/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:04:38 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/15 16:19:08 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
