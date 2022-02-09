/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:38 by azanane           #+#    #+#             */
/*   Updated: 2022/02/09 13:40:09 by azanane          ###   ########.fr       */
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
	int				who;
	int				nb_philo;
	int				eat;
	int				die;
	int				sleep;
	int				nb_meals;
	int				ct_meals;
	int				ct_time;
	int				tmp;
	struct timeval	st;
	struct timeval	end;
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
	pthread_mutex_t	mutex_in;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*mutex_right;
}	t_val;

typedef struct s_philo
{
	int				p;
	int				n;
	int				life;
	pthread_t		pid;
	t_val			v;
	struct timeval	st;
	struct timeval	end;
	struct timeval	last_meal;
	struct timeval	check;
}	t_philo;

typedef struct s_variables
{
	int				i;
	int				n;
	int				j;
	float			time_die;
	int				brk;
	int				ct;
}	t_variables;

int		main(int ac, char **av);
int		ft_thread(t_philo *p, t_variables *var, int len);
void	*routine(void *arg);
float	gtime(struct timeval *st, struct timeval *end);
int		ft_atoi(const char	*str);
void	ft_pstr(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);

#endif
