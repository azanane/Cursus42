/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:31:58 by azanane           #+#    #+#             */
/*   Updated: 2022/01/05 17:44:53 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWP_H
# define PUSH_SWP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_v
{
	int	i;
	int	n;
	int	j;
	int	d;
	int	y;
	int	ct;
	int	tmp;
	int	**tab;
}	t_v;

int		main(int ac, char **av);
int		ft_parsing(char **av, t_v *v);
int		ft_kill_malloc_int(int **tab, int size);
void	ft_radix(t_v *v);
void	ft_operation(t_v *v, char *op);

#endif