/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:21:20 by azanane           #+#    #+#             */
/*   Updated: 2022/01/05 18:01:43 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

void	ft_swp(t_v *v, int dim, char *op)
{
	v->tmp = v->tab[dim][1];
	v->tab[dim][1] = v->tab[dim][0];
	v->tab[dim][0] = v->tmp;
	ft_putstr_fd(op, 1);
}

void	ft_operation(t_v *v, char *op)
{
	if (op == "sa")
		ft_swp(v, 0, "sa\n");
	if (op == "sb")
		ft_swp(v, 1, "sb\n");
	if (op == "ss")
	{
		ft_swp(v, 0, "ss\n");
		ft_swp(v, 1, "");
	}
}
