/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:47:50 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/07 15:21:37 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_parsing_3(int *i, t_algo *a)
{
	t_v		v;
	char	**line;

	v.tab = malloc(sizeof(int *) * *i);
	if (!v.tab)
		return (0);
	*i = -1;
	v.j = 0;
	while (a->file[++(*i)])
	{
		v.n = 0;
		line = ft_split(a->file[*i], ' ');
		while (a->file[*i][v.n])
			v.n++;
		v.tab[*i] = malloc(sizeof(int) * v.n);
		if (!v.tab[*i])
			return (ft_free_int(v.tab, *i));
		v.n = -1;
		while (line[++v.n])
			v.tab[v.j][v.n] = ft_atoi(line[v.n]);
		ft_freee(line);
		v.j++;
	}
	ft_wireframe(v.tab, v.j, v.n, a);
	return (0);
}

void	ft_parsing_2(t_algo *a, t_v v, int *i)
{
	a->s = get_next_line(v.fd);
	while (a->s)
	{
		v.n = 0;
		while (a->s[v.n])
			v.n++;
		a->file[*i] = malloc(sizeof(char) * (v.n + 1));
		if (!a->file[*i])
		{
			ft_freee(a->file);
			return ;
		}
		a->file[*i][v.n] = 0;
		v.n = -1;
		while (a->s[++v.n])
			a->file[*i][v.n] = a->s[v.n];
		free(a->s);
		a->s = NULL;
		a->s = get_next_line(v.fd);
		*i += 1;
	}
	close(v.fd);
	ft_parsing_3(i, a);
}

void	ft_parsing(int i, t_algo *a, char *av)
{
	t_v	v;

	v.fd = open(av, O_RDONLY);
	a->file = malloc(sizeof(char *) * (i + 1));
	if (!a->file)
		return ;
	a->file[i] = 0;
	i = 0;
	ft_parsing_2(a, v, &i);
}

int	ft_event(int keycode, t_algo *a)
{
	if (keycode == 53)
	{
		mlx_destroy_window(a->ptr, a->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	t_algo	a;

	if (ac != 2)
		return (0);
	a.ptr = mlx_init();
	if (!a.ptr)
		return (0);
	fd = open(av[1], O_RDONLY);
	a.s = get_next_line(fd);
	i = 0;
	while (a.s)
	{
		if (a.s[0] != '\n')
			i++;
		ft_free(a.s);
		a.s = NULL;
		a.s = get_next_line(fd);
	}
	close(fd);
	ft_parsing(i, &a, av[1]);
	mlx_hook(a.win, 2, 1L << 0, ft_event, &a);
	mlx_loop(a.ptr);
	return (0);
}
