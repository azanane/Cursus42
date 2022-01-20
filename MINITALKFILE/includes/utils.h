/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:23:42 by azanane           #+#    #+#             */
/*   Updated: 2022/01/20 09:59:23 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_val
{
	int	i;
	int	j;
	int	n;
	int	x;
}	t_val;

int		ft_atoi(const char	*str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd);

#endif