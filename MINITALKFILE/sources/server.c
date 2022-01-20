/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:08:50 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/20 18:11:37 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

/*
*	Mettre les valeurs dans un ableau d'int.
*/

void	handler(int signum)
{
}

int	main(void)
{
	t_server			s;
	struct sigaction	sact;
	int					*tab;

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
