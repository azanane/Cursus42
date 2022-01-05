/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:05:17 by azanane           #+#    #+#             */
/*   Updated: 2021/11/10 11:21:02 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(dst);
	if (size < count || size == 0)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && i + count < size - 1)
	{
		dst[i + count] = src[i];
		i++;
	}
	dst[i + count] = '\0';
	return (count + ft_strlen(src));
}
