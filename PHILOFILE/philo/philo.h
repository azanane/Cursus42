/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:38 by azanane           #+#    #+#             */
/*   Updated: 2022/02/04 13:31:23 by azanane          ###   ########.fr       */
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
	int				i;
	int				n;
	int				time;
	int				who;
	int				nb_philo;
	int				eat;
	int				die;
	int				sleep;
	int				nb_meals;
	int				ct_meals;
	int				ct_time;
	int				tmp;
}	t_rout;

typedef struct s_val
{
	int				which_p;
	int				total_p;
	int				time_e;
	int				time_s;
	int				time_d;
	int				total_m;
	int				total_v;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*mutex_tab;
}	t_val;

typedef struct s_philo
{
	int				p;
	int				n;
	int				*frk;
	int				life;
	pthread_t		pid;
	t_val			v;
	struct timeval	current_time;
	struct timeval	current_time2;
	struct timeval	current_time3;
}	t_philo;

typedef struct s_variables
{
	int				i;
	int				n;
	int				j;
	int				ct;
}	t_variables;

int		main(int ac, char **av);
int		ft_thread(t_philo *p, t_variables *var, int len);
void	*routine(void *arg);
void	mutex_lock_all(void *arg, t_rout *r);
void	mutex_unlock_all(void *arg, t_rout *r);
int		fork_avaliable(void *arg, t_rout *r);
int		ft_atoi(const char	*str);
void	ft_pstr(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);

#endif
