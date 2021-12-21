/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:46:09 by azanane           #+#    #+#             */
/*   Updated: 2021/12/20 15:26:53 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
	int		x;
}	t_val;

char	*ft_free(char	*s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int	*rd);
int		ft_strchr(char	*s, int c);
int		ft_strlen(char	*str);
char	*ft_substr(char	*s, int start, size_t	len);

#endif
