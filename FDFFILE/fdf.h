/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:14:32 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/26 17:35:14 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libmlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_v
{
	int		j;
	int		n;
	int		d;
	int		k;
	int		m;
	int		x;
	int		**tab;
	int		fd;
}	t_v;

typedef struct s_s
{
	char	**file;
	char	*s;
}	t_s;

typedef struct s_algo
{
	int		x;
	int		y;
	int		dy;
	int		dy1;
	int		dx;
	int		dp;
	int		de;
	int		dne;
	void	*ptr;
	void	*win;
}	t_algo;

int		main(/*int	argc, char	**argv*/void);
void	ft_parsing(int i);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char	*str);
void	ft_wireframe(int	**tab, int ymax, int xmax);

#endif