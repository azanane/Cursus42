/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:33:20 by azanane           #+#    #+#             */
/*   Updated: 2022/01/06 13:31:46 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swp.h"

void	ft_parsing_4(t_v *v)
{
	
}

void	ft_parsing_3(char **av, t_v *v)
{
	while (av[++v->i])
	{
		v->n = -1;
		while (av[v->i][++(v->n)])
		{
			if (ft_isdigit(av[v->i][v->n]) == 1)
			{
				v->y = -1;
				v->tab[0][v->d] = ft_atoi(av[v->i] + v->n, &v->n);
				while (++v->y < v->d)
				{
					if (v->tab[0][v->y] == v->tab[0][v->d])
					{
						ft_kill_malloc_int(v->tab, 2);
						write(1, "Error\n", 6);
						return ;
					}
				}
				v->d++;
			}
		}
	}
	ft_parsing_4(v);
	// ft_radix(v);
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
			if (ft_isdigit(av[v->i][v->n]) == 0 && av[v->i][v->n] != ' ')
			{
				write(1, "Error\n", 6);
				return (0);
			}
			if (ft_isdigit(av[v->i][v->n]) == 1
				&& (av[v->i][v->n + 1] == ' ' || av[v->i][v->n + 1] == 0))
				v->ct++;
		}
		if (v->tmp == v->ct)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (v->ct < 2)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_v	v;

	if (ac < 2)
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
