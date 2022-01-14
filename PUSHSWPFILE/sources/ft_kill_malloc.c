/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:37:09 by azanane           #+#    #+#             */
/*   Updated: 2022/01/14 14:36:37 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swp.h"

int	ft_kill_malloc_int(int **tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(tab[i]);
	free(tab);
	return (0);
}
