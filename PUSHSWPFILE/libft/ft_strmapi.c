/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:08:22 by azanane           #+#    #+#             */
/*   Updated: 2021/11/12 10:48:11 by azanane          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (tab == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
