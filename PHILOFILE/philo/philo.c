/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:52:09 by azanane           #+#    #+#             */
/*   Updated: 2022/02/08 17:40:35 by azanane          ###   ########.fr       */
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

void	ft_getval(char **av, t_variables *var)
{
	t_philo	*p;

	if (ft_atoi(av[1]) == 0)
		ft_error_arg(1, "p");
	p = malloc(sizeof(struct s_philo) * ft_atoi(av[1]));
	if (!p)
		return ;
	while (++var->i < ft_atoi(av[1]))
	{
		p[var->i].v.total_v = var->ct;
		p[var->i].v.total_p = ft_atoi(av[1]);
		p[var->i].v.time_d = ft_atoi(av[2]);
		p[var->i].v.time_e = ft_atoi(av[3]);
		p[var->i].v.time_s = ft_atoi(av[4]);
		if (var->ct == 5)
			p[var->i].v.total_m = ft_atoi(av[5]);
	}
	var->i = -1;
	ft_thread(p, var, ft_atoi(av[1]));
}

void	ft_check_args(char **av, t_variables *var)
{
	var->i = 0;
	var->ct = 0;
	while (av[++var->i])
	{
		var->n = -1;
		while (av[var->i][++var->n])
		{
			if (ft_isdigit(av[var->i][var->n]) == 1
				&& (var->n == 0 || av[var->i][var->n - 1] == ' '
					|| av[var->i][var->n - 1] == '+'))
				var->ct++;
			if (av[var->i][var->n] == '+'
				&& var->n > 0 && av[var->i][var->n - 1] != ' ')
				ft_error_arg(var->ct, "");
			if (ft_isdigit(av[var->i][var->n]) == 0 && av[var->i][var->n] != ' '
				&& av[var->i][var->n] != '+')
				ft_error_arg(var->ct, "");
		}
	}
	if (var->ct < 4 || var->ct > 5)
		ft_error_arg(var->i, "n");
}

int	main(int ac, char **av)
{
	t_variables			var;

	ft_check_args(av, &var);
	var.i = -1;
	ft_getval(av, &var);
	ac = 0;
	return (0);
}
