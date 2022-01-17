/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:33:20 by azanane           #+#    #+#             */
/*   Updated: 2022/01/14 15:56:10 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swp.h"

void	ft_parsing_4(t_v *v)
{
	v->ct = 0;
	v->i = 0;
	while (++v->i < v->d)
	{
		if (v->tab[0][v->i] < v->tab[0][v->i - 1])
			v->ct++;
	}
	if (v->ct == 0)
	{
		ft_kill_malloc_int(v->tab, 2);
		exit (1);
	}
	ft_index(v);
	if (v->d < 6)
		ft_sort(v);
	else if (v->d >= 6)
		ft_radix(v);
	ft_kill_malloc_int(v->tab, 2);
}

void	ft_parsing_3(char **av, t_v *v)
{
	while (av[++v->i])
	{
		v->n = -1;
		while (av[v->i][++(v->n)])
		{
			if (ft_isdigit(av[v->i][v->n]) == 1 || av[v->i][v->n] == '-')
			{
				v->y = -1;
				v->tab[0][v->d] = ft_atol(v->tab, av[v->i] + v->n, &v->n);
				while (++v->y < v->d)
				{
					if (v->tab[0][v->y] == v->tab[0][v->d])
						ft_error(v->tab);
				}
				v->d++;
			}
		}
	}
	ft_parsing_4(v);
}

void	ft_parsing_2(char **av, t_v *v)
{
	v->tab = malloc(sizeof(int *) * 2);
	if (!v->tab)
		return ;
	v->tab[0] = malloc(sizeof(int) * v->ct);
	v->tab[1] = malloc(sizeof(int) * v->ct);
	if (!v->tab[0] || !v->tab[1])
	{
		ft_kill_malloc_int(v->tab, 2);
		return ;
	}
	v->i = 0;
	v->d = 0;
	ft_parsing_3(av, v);
}

int	ft_parsing(char **av, t_v *v)
{
	while (av[++(v->i)])
	{
		v->n = -1;
		v->tmp = v->ct;
		while (av[v->i][++(v->n)])
		{
			if ((ft_isdigit(av[v->i][v->n]) == 0 && av[v->i][v->n] != ' '
				&& av[v->i][v->n] != '+' && av[v->i][v->n] != '-')
				|| ((av[v->i][v->n] == '+' || av[v->i][v->n] == '-')
				&& ft_isdigit(av[v->i][v->n + 1]) == 0)
				|| ((av[v->i][v->n] == '+' || av[v->i][v->n] == '-')
				&& (v->n != 0 && av[v->i][v->n - 1] != ' ')))
				ft_error(NULL);
			if (ft_isdigit(av[v->i][v->n]) == 1
				&& (av[v->i][v->n + 1] == ' ' || av[v->i][v->n + 1] == 0))
				v->ct++;
		}
		if (v->tmp == v->ct)
			ft_error(NULL);
	}
	if (v->ct < 2)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_v	v;

	if (ac <= 1)
		return (0);
	v.i = 0;
	if (ft_quote(ac, av, v) == 1)
		return (0);
	v.i = 0;
	v.ct = 0;
	if (av[1][0] == 0 && ac == 2)
		return (0);
	if (ft_parsing(av, &v) == 0)
		return (0);
	ft_parsing_2(av, &v);
	return (0);
}
