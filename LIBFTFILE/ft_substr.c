/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:51:13 by azanane           #+#    #+#             */
/*   Updated: 2021/11/12 18:01:38 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
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
		if (len < ft_strlen(s + start))
			i = len;
	}
	str = malloc(sizeof(char) * i + 1);
	if (str == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}
