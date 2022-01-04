/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:14:32 by anaszanane        #+#    #+#             */
/*   Updated: 2022/01/04 17:07:57 by azanane          ###   ########.fr       */
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
# include "utils/utils.h"

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

typedef struct s_algo
{
	int		x;
	int		y;
	int		dy;
	int		dy1;
	int		dx;
	int		dx1;
	int		m;
	double	c;
	char	*s;
	char	**file;
	int		**col;
	int		col1;
	int		col2;
	double	col3;
	void	*ptr;
	void	*win;
	void	*img;
}	t_algo;

int		main(int ac, char **av);
void	ft_parsing(int i, t_algo *a, char *av);
void	ft_wireframe(int **tab, int ymax, int xmax, t_algo	*a);
char	**ft_freee(char	**tab);

#endif