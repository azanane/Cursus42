/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:19:29 by azanane           #+#    #+#             */
/*   Updated: 2022/01/04 16:31:18 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../get_next_line/get_next_line.h"

int	ft_b(char *str, char *base)
{
	int	nb;
	int	i;
	int	j;
	int	ct;

	nb = 0;
	i = -1;
	ct = 1;
	if (str[++i] == '-')
		ct *= -1;
	else if (str[i] == '+')
		i++;
	while (str[i - 1] != 'x' && str[i - 1] != 'X')
		i++;
	while (str[i] != '\n' && str[i] != 0 && str[i] != ' ')
	{
		j = 0;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_toupper(str[i]);
		while (base[j] && base[j] != str[i])
			j++;
		nb = nb * ft_strlen(base) + j;
		i++;
	}
	return (nb);
}
