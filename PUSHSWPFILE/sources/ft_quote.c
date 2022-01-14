/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:18:17 by azanane           #+#    #+#             */
/*   Updated: 2022/01/14 14:36:37 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swp.h"

int	ft_quote(int ac, char **av, t_v v)
{
	while (av[++(v.i)])
	{
		v.n = -1;
		while (av[v.i][++(v.n)])
		{
			if (av[v.i][v.n] == ' ')
			{
				while (av[v.i][++(v.n)])
				{
					if (ft_isdigit(av[v.i][v.n]) == 1 && ac > 2)
					{
						write(2, "Error\n", 6);
						return (1);
					}
				}
			}
		}
	}
	return (0);
}
