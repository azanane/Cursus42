/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:21:20 by azanane           #+#    #+#             */
/*   Updated: 2022/01/11 17:47:03 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

void	ft_push(t_v *v, int dim, char *op)
{
	int	i;
	int	dim2;
	int	max;
	int	max2;

	if (dim == 0)
	{
		dim2 = 1;
		max = v->d - v->ct2;
		max2 = v->ct2;
	}
	else
	{
		dim2 = 0;
		max = v->ct2;
		max2 = v->d - v->ct2;
	}
	i = max;
	while (--i >= 0)
		v->tab[dim][i + 1] = v->tab[dim][i];
	v->tab[dim][i] = v->tab[dim2][i];
	i = -1;
	while (++i < max2)
		v->tab[dim2][i] = v->tab[dim2][i + 1];
	ft_putstr_fd(op, 1);
}

void	ft_rotate(t_v *v, int dim, char *op)
{
	int	i;
	int	tmp;
	int	max;

	if (dim == 0)
		max = v->d - v->ct2;
	else
		max = v->ct2;
	i = -1;
	tmp = v->tab[dim][0];
	while (++i < max - 1)
		v->tab[dim][i] = v->tab[dim][i + 1];
	v->tab[dim][i] = tmp;
	ft_putstr_fd(op, 1);
}

void	ft_swp(t_v *v, int dim, char *op)
{
	v->tmp = v->tab[dim][1];
	v->tab[dim][1] = v->tab[dim][0];
	v->tab[dim][0] = v->tmp;
	ft_putstr_fd(op, 1);
}

void	ft_operation(t_v *v, char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		ft_swp(v, 0, "sa\n");
	else if (ft_strncmp(op, "sb", 2) == 0)
		ft_swp(v, 1, "sb\n");
	else if (ft_strncmp(op, "ss", 2) == 0)
	{
		ft_swp(v, 0, "ss\n");
		ft_swp(v, 1, "");
	}
	else if (ft_strncmp(op, "ra", 2) == 0)
		ft_rotate(v, 0, "ra\n");
	else if (ft_strncmp(op, "pa", 2) == 0)
		ft_push(v, 0, "pa\n");
	else if (ft_strncmp(op, "pb", 2) == 0)
		ft_push(v, 1, "pb\n");
}
