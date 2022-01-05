/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:58:54 by azanane           #+#    #+#             */
/*   Updated: 2021/11/12 13:23:13 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	n)
{
	size_t	i;
	char	*str;
	char	*str1;

	if (!dest && !src)
		return (NULL);
	str = (char *)dest;
	str1 = (char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = str1[i];
		i++;
	}
	return (dest);
}
