/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:42:03 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/20 12:39:22 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	ft_sendchar(unsigned char c, int pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			dprintf(1, "1");
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			dprintf(1, "2");
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		bit >>= 1;
	}
	dprintf(1, "\n");
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	i = -1;
	while (av[2][++i])
		ft_sendchar(av[2][i], pid);
	return (0);
}
