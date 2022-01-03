/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:19:29 by azanane           #+#    #+#             */
/*   Updated: 2022/01/03 19:10:15 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_b(char *str)
{
	int	nb;
	char	s[9];
	int	i;
	int	n;

	s[8] = 0;
	nb = 0;
	i = 0;
	n = 0;
	// while (str[i - 1] != 'x')
	// 	i++;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z'))
	{
		s[n] = str[i];
		n++;
		i++;
	}
	dprintf(1, "%d\n", 0xFFFFFF);
	dprintf(1, "%d\n", (int)s[0]);
	dprintf(1, "%s\n", s);
	nb = *(int *)s;
	return (nb);
}
