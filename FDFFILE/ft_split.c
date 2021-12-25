/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaszanane <anaszanane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:50:40 by azanane           #+#    #+#             */
/*   Updated: 2021/12/24 11:26:15 by anaszanane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_base(char str, char	*charset)
{
	if (str == *charset)
		return (1);
	return (0);
}

static char	*ft_str_up(char const *src, char *charset, int *i)
{
	char	*tab;
	int		j;
	int		size;

	j = 0;
	while (ft_check_base(src[*i], charset) == 1)
		*i += 1;
	size = *i;
	while (ft_check_base(src[size], charset) == 0 && src[size] != '\0')
		size++;
	size -= *i;
	tab = malloc(sizeof(char) * (size + 1));
	if (tab == 0)
		return (0);
	while (ft_check_base(src[*i], charset) == 0 && src[*i] != '\0')
	{
		tab[j] = src[*i];
		*i += 1;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static int	ft_count_words(char const *str, char *charset)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (str[i] && charset != 0)
	{
		if ((ft_check_base (str[i], charset) == 1)
			&& (ft_check_base(str[i + 1], charset) == 0)
			&& (str[i + 1] != '\0'))
			ct++;
		i++;
	}
	if (ft_check_base(str[0], charset) == 1 || str[0] == 0)
		return (ct + 1);
	return (ct + 2);
}

static int	ft_pb_malloc(char	**tab)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof (char *) * ft_count_words(s, &c));
	if (tab == 0)
		return (NULL);
	while (j < ft_count_words(s, &c) - 1)
	{
		tab[j] = ft_str_up(s, &c, &i);
		if (tab[j] == 0)
		{
			ft_pb_malloc(tab);
			return (0);
		}
		j++;
	}
	tab[j] = 0;
	return (tab);
}
