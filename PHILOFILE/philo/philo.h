/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:38 by azanane           #+#    #+#             */
/*   Updated: 2022/02/02 17:48:01 by azanane          ###   ########.fr       */
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

typedef struct s_rout
{

	struct timeval	current_time;
	struct timeval	current_time2;
	int				nb_philo;
	int				eat;
	int				die;
	int				sleep;
	int				nb_meals;
	int				ct_meals;
	int				tmp;
	int				who;
}	t_rout;

typedef struct s_philo
{
	int				p;
	int				n;
	int				*tb;
	int				*frk;
	int				nph;
	pthread_t		pid;
	pthread_mutex_t	mutex_1;
}	t_philo;

typedef struct s_val
{
	int				i;
	int				n;
	int				ct;
	int				*tab;
	pthread_mutex_t	mutex;
}	t_val;

int		main(int ac, char **av);
int		ft_thread(t_val *v, int len);
void	*routine(void *arg);
int		p_fork(t_rout *r, int *frk, int i, int nb);
int		ft_atoi(const char	*str);
void	ft_pstr(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long n, int fd);
int		ft_isdigit(int c);

#endif
