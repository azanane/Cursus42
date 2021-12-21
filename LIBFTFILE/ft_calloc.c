/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:12:44 by azanane           #+#    #+#             */
/*   Updated: 2021/11/12 12:43:35 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	char	*tb;
	size_t	i;

	i = 0;
	tb = malloc(size * (count));
	if (tb == 0)
		return (0);
	ft_bzero(tb, count * size);
	return ((void *)tb);
}
