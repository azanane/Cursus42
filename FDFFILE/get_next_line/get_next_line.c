/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:33:13 by azanane           #+#    #+#             */
/*   Updated: 2021/12/27 21:21:11 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char	*s)
{
	free(s);
	s = NULL;
	return (NULL);
}

char	*ft_line(char	*s, int	*i)
{
	char	*str;

	*i = 0;
	if (!s)
		return (NULL);
	while (s[*i] && s[*i] != '\n')
		*i += 1;
	if (s[*i] == '\n')
		str = malloc(sizeof(char) * *i + 2);
	else
		str = malloc(sizeof(char) * *i + 1);
	if (str == 0)
		return (NULL);
	*i = -1;
	while (s[++(*i)] && s[*i] != '\n')
		str[*i] = s[*i];
	if (s[*i] == '\n')
	{
		str[*i] = '\n';
		str[*i + 1] = '\0';
	}
	else
		str[*i] = '\0';
	return (str);
}

char	*ft_fill(char *s, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		rd;
	char	*tmp;

	rd = 1;
	buff[BUFFER_SIZE] = '\0';
	while (rd > 0 && ft_strchr(s, '\n') == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
		{
			if (s)
				return (s);
			s = malloc(sizeof(char) * 1);
			s[0] = '\0';
			return (s);
		}
		tmp = s;
		s = ft_strjoin(s, buff, &rd);
		if (tmp)
			free(tmp);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*dest;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s = ft_fill(s, fd);
	if (s && !*s)
	{
		s = ft_free(s);
		return (NULL);
	}
	dest = ft_line(s, &i);
	if (s && s[i] == '\0')
		s = ft_free(s);
	if (dest && s && !(*dest))
	{
		dest = ft_free(dest);
		s = ft_free(s);
		return (NULL);
	}
	s = ft_substr(s, i + 1, ft_strlen(s) - i + 1);
	if (s && !(*s))
		s = ft_free(s);
	return (dest);
}
