/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:22:55 by azanane           #+#    #+#             */
/*   Updated: 2021/11/12 19:46:16 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_gdl(const char	*s1, const char	*set, size_t	*i, size_t	*j)
{
	size_t	n;

	n = 0;
	while (s1[*i] && set[n])
	{
		n = 0;
		while (set[n] && set[n] != s1[*i])
			n++;
		*i += 1;
	}
	*i -= 1;
	n = 0;
	while (s1[*j])
		*j += 1;
	*j -= 1;
	while (*j > *i && set[n])
	{
		n = 0;
		while (set[n] && set[n] != s1[*j])
			n++;
		*j -= 1;
	}
	if (*i != *j)
		*j += 1;
}

static int	ft_gdl2(char const	*s1, char	*str, size_t	*i, size_t	*j)
{
	size_t	n;

	n = 0;
	if (*i != ft_strlen(s1) - 1 && *j)
	{
		while (*i < *j)
		{
			str[n] = s1[*i];
			n++;
			*i += 1;
		}
		str[n] = s1[*i];
		n++;
	}
	return (n);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	if (set[0] == '\0')
		return (ft_substr(s1, 0, i));
	i = 0;
	j = 0;
	ft_gdl(s1, set, &i, &j);
	str = malloc(sizeof(char) * (j - i + 2));
	if (str == 0)
		return (0);
	n = ft_gdl2(s1, str, &i, &j);
	str[n] = '\0';
	return (str);
}
