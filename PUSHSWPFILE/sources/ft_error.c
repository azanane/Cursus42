/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:14:02 by azanane           #+#    #+#             */
/*   Updated: 2022/01/14 14:36:37 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swp.h"

void	ft_error(int **tab)
{
	if (tab != NULL)
		ft_kill_malloc_int(tab, 2);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
