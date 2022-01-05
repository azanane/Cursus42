/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:47:50 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/04 18:44:59 by azanane          ###   ########.fr       */
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
	ft_wireframe(v.tab, v.j, v.n, a);
}

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

int	ft_event(int keycode, t_algo *a)
{
	if (keycode == 53)
	{
		mlx_destroy_window(a->ptr, a->win);
		exit(0);
	}
	// if (keycode == 27)
	// {
	// 	a->img = mlx_new_image(a->ptr, 1920, 1080);
	// 	mlx_put_image_to_window(a->ptr, a->win, a->img, -10, 0);
	// 	main(ac, av);
	// }
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
	mlx_hook(a.win, 2, 1L << 0, ft_event, &a);
	mlx_loop(a.ptr);
	return (0);
}
