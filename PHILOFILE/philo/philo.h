/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:38 by azanane           #+#    #+#             */
/*   Updated: 2022/01/26 18:19:49 by azanane          ###   ########.fr       */
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

typedef struct s_val
{
	int	i;
	int	n;
	int	ct;
	int	time;
	int	time2;
	int	*tab;
	int	*frk;
}	t_val;

typedef struct	s_philo
{

}	t_philo;

int		main(int ac, char **av);
void	ft_thread(t_val *v);
int		pass_fork(t_val *v, int i, int nb);
int		ft_atoi(const char	*str);
void	ft_pstr(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);

#endif
