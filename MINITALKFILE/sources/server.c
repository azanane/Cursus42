/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:08:50 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/22 16:45:57 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

/*
	Mettre les valeurs dans un tableau d'int.
*/

void	handler(int signum)
{
	static int	bit = 0;
	static int	c = 0;

	dprintf(1, "%d\n", c);
	if (signum == 30)
        c += (128 >> bit);
    bit += 1;
    if (bit == 8)
    {
        ft_putchar_fd(c, 1);
        bit = 0;
        c = 0;
    }
}

int	main(void)
{
	t_server			s;
	struct sigaction	sact;

	sigemptyset(&sact.sa_mask);
	sact.sa_flags = 0;
	sact.sa_handler = handler;
	s.pid = getpid();
	ft_printf("%d\n", s.pid);
	while (1)
	{
		sigaction(SIGUSR1, &sact, NULL);
		sigaction(SIGUSR2, &sact, NULL);
		pause();
	}
	return (0);
}
