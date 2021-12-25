/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:43:11 by azanane           #+#    #+#             */
/*   Updated: 2021/12/24 14:54:01 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

typedef struct s_val
{
	int		i;
	int		j;
	int		n;
	int		k;
}	t_val;

char	*ft_free(char	*s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int	*rd);
int		ft_strchr(char	*s, int c);
int		ft_strlen(char	*str);
char	*ft_substr(char	*s, int start, size_t	len);

#endif
