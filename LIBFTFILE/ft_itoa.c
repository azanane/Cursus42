/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:52:21 by azanane           #+#    #+#             */
/*   Updated: 2021/11/12 10:51:50 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_malloc(int	*n)
{
	int				i;
	unsigned int	ct;

	i = 1;
	ct = 2;
	while (!(*n / i <= 9 && *n / i >= -9))
	{
		i = i * 10;
		ct++;
	}
	if (*n < 0)
		ct++;
	return (ct);
}

static unsigned int	ft_pwr(unsigned int	*index, int	*n)
{
	unsigned int	temp;
	unsigned int	power;

	temp = 1;
	power = ft_count_malloc(n) - *index - 2;
	while (power > 0)
	{
		temp = temp * 10;
		power--;
	}
	return (temp);
}

static char	ft_nbr(int	*n, unsigned int	*i)
{
	char			c;
	unsigned int	*index;

	index = i;
	if (*n >= 0)
		c = *n / ft_pwr(index, n) % 10 + '0';
	else
		c = -*n / ft_pwr(index, n) % 10 + '0';
	return (c);
}

char	*ft_itoa(int n)
{
	char				*tab;
	unsigned int		i;

	tab = malloc(sizeof(char) * ft_count_malloc(&n));
	if (tab == 0)
		return (0);
	i = 0;
	while (i < ft_count_malloc(&n) - 1)
	{
		tab[i] = ft_nbr(&n, &i);
		i++;
	}
	tab[i] = '\0';
	i = 0;
	if (n < 0)
		tab[i] = '-';
	return (tab);
}
