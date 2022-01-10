/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:15:19 by azanane           #+#    #+#             */
/*   Updated: 2022/01/10 12:38:50 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*hay, const char	*needle, size_t	len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (i < len && hay[i])
	{
		j = 0;
		while (needle[j] == hay[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&hay[i]);
			j++;
		}
		i++;
	}
	if (needle[j] == '\0')
		return ((char *)&hay[i]);
	return (0);
}
