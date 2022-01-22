/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:42:03 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/22 13:19:27 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	ft_sendchar(unsigned char c, int pid)
{
	unsigned int	bit;

	bit = 128;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		bit /= 2;
		usleep(500);
	}
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
