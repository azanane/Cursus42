/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:09 by azanane           #+#    #+#             */
/*   Updated: 2022/02/02 08:44:00 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_arg(int i, char *err)
{
	if (err[0] == 'n')
		ft_pstr("Error: Need 4 or 5 arguments.\n", 2);
	else if (err[0] == 'p')
		ft_pstr("Error: Need 1 philosopher at least (First argument).\n", 2);
	else
	{
		ft_pstr("Error found in the argument number ", 2);
		ft_putchar_fd((i + 49), 2);
		ft_pstr(".\n", 2);
		ft_pstr("Some common errors to avoid:\n", 2);
		ft_pstr("	- Found a negative number;\n", 2);
		ft_pstr("	- Found an non-digit argument (Exception for '+');\n", 2);
		ft_pstr("	- Found a '+', but not before a number.\n", 2);
	}
	exit (-1);
}

void	ft_getval(char **av, t_val *v)
{
	v->tab = malloc(sizeof(int) * v->ct);
	if (!v->tab)
		return ;
	v->i = 0;
	while (av[++v->i])
	{
		v->n = -1;
		while (av[v->i][++v->n])
		{
			if (v->n == 0 || av[v->i][v->n - 1] == ' ')
				v->tab[v->i - 1] = ft_atoi(av[v->i] + v->n);
		}
	}
	if (v->tab[0] == 0)
	{
		free (v->tab);
		ft_error_arg(1, "p");
	}
}

void	ft_check_args(char **av, t_val *v)
{
	v->i = 0;
	v->ct = 0;
	while (av[++v->i])
	{
		v->n = -1;
		while (av[v->i][++v->n])
		{
			if (ft_isdigit(av[v->i][v->n]) == 1
				&& (v->n == 0 || av[v->i][v->n - 1] == ' '
					|| av[v->i][v->n - 1] == '+'))
				v->ct++;
			if (av[v->i][v->n] == '+' && v->n > 0 && av[v->i][v->n - 1] != ' ')
				ft_error_arg(v->ct, "");
			if (ft_isdigit(av[v->i][v->n]) == 0 && av[v->i][v->n] != ' '
				&& av[v->i][v->n] != '+')
				ft_error_arg(v->ct, "");
		}
	}
	if (v->ct < 4 || v->ct > 5)
		ft_error_arg(v->i, "n");
}

int	main(int ac, char **av)
{
	t_val			v;
	static int		len;

	ft_check_args(av, &v);
	ft_getval(av, &v);
	ac++;
	v.i = -1;
	len = v.tab[0];
	ft_thread(&v, len);
	return (0);
}
