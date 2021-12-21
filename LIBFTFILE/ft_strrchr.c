/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:36:40 by azanane           #+#    #+#             */
/*   Updated: 2021/11/12 15:14:33 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if (s[i] == (char)c && (char)c == '\0')
		return ((char *)s + i);
	else if (s[j] == (char)c)
		return ((char *)s + j);
	return (0);
}
