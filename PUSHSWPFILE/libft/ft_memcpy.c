/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:58:54 by azanane           #+#    #+#             */
/*   Updated: 2022/01/12 12:07:15 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	n)
{
	size_t	i;
	int		*str;
	int		*str1;

	if (!dest && !src)
		return (NULL);
	str = (int *)dest;
	str1 = (int *)src;
	i = 0;
	while (i < n)
	{
		str[i] = str1[i];
		i++;
	}
	return (dest);
}
