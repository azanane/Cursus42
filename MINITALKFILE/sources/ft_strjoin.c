/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:18:24 by azanane           #+#    #+#             */
/*   Updated: 2022/01/19 09:53:23 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_free(char	*s)
{
	free(s);
	s = NULL;
	return (NULL);
}

char	*ft_strjoin_2(char	*s1, char	*s2)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	t_val	val;

	val.j = ft_strlen(s1);
	val.n = ft_strlen(s2);
	val.i = -1;
	val.x = 0;
	if (!s1)
		s1 = ft_strjoin_2(s1, s2);
	str = malloc(sizeof(char) * (val.n + val.j + 2));
	if (str == 0)
		return (NULL);
	while (++val.i < val.j)
		str[val.i] = s1[val.i];
	if (val.j != 0)
		str[val.i] = s1[val.i];
	while (val.i < val.j + val.n)
	{
		str[val.i] = s2[val.x];
		val.i++;
		val.x++;
	}
	if (val.n != 0)
		str[val.i] = s2[val.x];
	str[val.i] = '\0';
	return (str);
}
