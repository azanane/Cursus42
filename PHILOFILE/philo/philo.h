/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:38 by azanane           #+#    #+#             */
/*   Updated: 2022/02/01 19:47:58 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int			toeat;
	int			todie;
	int			tosleep;
	int			nph;
	struct val	*val;
	pthread_t	philoid;
	int			time;
	int			time2;
	int			*frk;
}	t_philo;

typedef struct s_val
{
	int	i;
	int	n;
	int	ct;
	int	*tab;
}	t_val;

int		main(int ac, char **av);
int		ft_thread(t_val *v);
int		pass_fork(t_val *v, t_philo *p, int i, int nb);
int		ft_atoi(const char	*str);
void	ft_pstr(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);

#endif
