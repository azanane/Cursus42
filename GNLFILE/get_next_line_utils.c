/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:37:03 by azanane           #+#    #+#             */
/*   Updated: 2021/12/20 15:20:02 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char	*s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char	*s, int start, size_t	len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		i = ft_strlen(s + start);
		if (s && (int)len < ft_strlen(s + start))
			i = len;
	}
	str = malloc(sizeof(char) * i + 1);
	if (str == 0)
		return (0);
	j = -1;
	while (++j < i)
	{
		str[j] = s[start];
		start++;
	}
	str[j] = '\0';
	ft_free(s);
	return (str);
}

char	*ft_cheatmeal(char	*s1, char	*s2)
{
	s1 = malloc(sizeof(char) * 1);
	if (!s1)
		return (NULL);
	s1[0] = '\0';
	if (!s2 || s2[0] == 0)
		return (s1);
	if (s1)
		ft_free(s1);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, int *rd)
{
	char	*str;
	t_val	val;

	val.x = -1;
	val.i = -1;
	val.j = ft_strlen(s1);
	val.n = ft_strlen(s2);
	if (!s1)
		s1 = ft_cheatmeal(s1, s2);
	str = malloc(sizeof(char) * (val.n + val.j + 2));
	if (str == 0)
		return (NULL);
	while (++val.i < val.j)
		str[val.i] = s1[val.i];
	if (val.j != 0)
		str[val.i] = s1[val.i];
	while (++val.x < *rd && val.i < val.j + val.n)
	{
		str[val.i] = s2[val.x];
		val.i++;
	}
	if (val.n != 0)
		str[val.i] = s2[val.x];
	str[val.i] = '\0';
	return (str);
}
