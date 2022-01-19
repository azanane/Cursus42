/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:42:03 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/19 17:14:56 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sact;

	if (ac < 2 && ac > 3)
		return (0);
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = 0;
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR1);
	return (0);
}
