/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:44:09 by azanane           #+#    #+#             */
/*   Updated: 2021/12/19 15:33:26 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*s[OPEN_MAX];
	char		*dest[OPEN_MAX + 1];
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s[fd] = ft_fill(s[fd], fd);
	if (s[fd] && !*s[fd])
	{
		s[fd] = ft_free(s[fd]);
		return (NULL);
	}
	dest[fd] = ft_line(s[fd], &i);
	if (s[fd] && s[fd] == '\0')
		s[fd] = ft_free(s[fd]);
	if (dest[fd] && s[fd] && !(*dest[fd]))
	{
		dest[fd] = ft_free(dest[fd]);
		s[fd] = ft_free(s[fd]);
		return (NULL);
	}
	s[fd] = ft_substr(s[fd], i + 1, ft_strlen(s[fd]) - i + 1);
	if (s[fd] && !(*s[fd]))
		s[fd] = ft_free(s[fd]);
	return (dest[fd]);
}
