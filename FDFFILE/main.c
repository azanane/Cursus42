/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:47:50 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/03 17:54:41 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_freee(char	**tab)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		tab[j] = NULL;
		j++;
	}
	free(tab);
	return (NULL);
}

// void	ft_parsing_3(int	**tab, int	i, int	n, char	*ptr)
// {
// 	int	*tab2;
// 	t_v	v;

// 	tab2 = malloc(sizeof(int) * (i * n));
// 	v.j = -1;
// 	v.m = -1;
// 	while (++(v.j) < i)
// 	{
// 		v.d = -1;
// 		while(++(v.d) < n && ++v.m < i * n)
// 			tab2[v.m] = tab[v.j][v.d];
// 	}
// 	v.d = -1;
// 	v.j = tab2[0];
// 	while (++v.d < i * n)
// 	{
// 		if (tab2[v.d] < v.j)
// 			v.j = tab2[v.d];
// 	}
// 	v.m = v.j - 1;
// 	v.k = 1;
// 	v.fd = 0;
// 	while (v.fd < i * n + 1)
// 	{
// 		v.d = -1;
// 		while (++v.d < i * n)
// 		{
// 			if (tab2[v.d] > v.m && tab2[v.d] != v.j)
// 				v.m = tab2[v.d];
// 		}
// 		v.d = -1;
// 		printf(" %d \n", v.x);
// 		while (++v.d < i * n)
// 		{
// 			if (tab2[v.d] == v.m && tab2[v.d] != v.j/* && v.k == 1*/)
// 				tab2[v.d] = v.x - 1;/*(1 * v.k + ((v.m / INT_MAX) + 1));
// 			else if (tab2[v.d] == v.m && tab2[v.d] != v.j && v.k != 1)
// 				tab2[v.d] = v.x - (1 * v.k + ((v.m / INT_MAX) + 1)) / v.x; */
// 		}
// 		v.k += 1;
// 		v.x = v.x - 1;
// 		v.m = v.j - 1;
// 		v.fd++;
// 	}
// 	v.d = -1;
// 	while (++v.d < i * n)
// 	{
// 		printf(" %d ", tab2[v.d]);
// 	}
// }
// 
void	ft_parsing_2(int i, t_algo *a)
{
	t_v		v;
	char	**line;

	v.tab = malloc(sizeof(int *) * i);
	i = -1;
	v.j = 0;
	while (a->file[++i])
	{
		v.n = 0;
		line = ft_split(a->file[i], ' ');
		while (a->file[i][v.n])
			v.n++;
		v.tab[i] = malloc(sizeof(int) * v.n);
		v.n = -1;
		while (line[++v.n])
			v.tab[v.j][v.n] = ft_atoi(line[v.n]);
		ft_freee(line);
		v.j++;
	}
	// ft_freee(a->file);
	ft_wireframe(v.tab, v.j, v.n, a);
}
	// ft_parsing_3(v.tab, v.j, v.n, ptr);

void	ft_parsing(int i, t_algo *a, char *av)
{
	t_v	v;

	v.fd = open(av, O_RDONLY);
	a->file = malloc(sizeof(char *) * (i + 1));
	a->file[i] = 0;
	i = 0;
	a->s = get_next_line(v.fd);
	while (a->s)
	{
		v.n = 0;
		while (a->s[v.n])
			v.n++;
		a->file[i] = malloc(sizeof(char) * (v.n + 1));
		a->file[i][v.n] = 0;
		v.n = -1;
		while (a->s[++v.n])
			a->file[i][v.n] = a->s[v.n];
		free(a->s);
		a->s = NULL;
		a->s = get_next_line(v.fd);
		i++;
	}
	close(v.fd);
	ft_parsing_2(i, a);
}

int	ft_close(int keycode, t_algo *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->ptr, v->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*s;
	t_algo	a;

	if (ac != 2)
		return (0);
	a.ptr = mlx_init();
	fd = open(av[1], O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		if (s[0] != '\n')
			i++;
		ft_free(s);
		s = NULL;
		s = get_next_line(fd);
	}
	close(fd);
	ft_parsing(i, &a, av[1]);
	mlx_hook(a.win, 2, 1L << 0, ft_close, &a);
	mlx_loop(a.ptr);
	return (0);
}
