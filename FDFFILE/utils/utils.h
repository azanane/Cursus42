/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:26:45 by azanane           #+#    #+#             */
/*   Updated: 2022/01/04 16:29:08 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

int		ft_b(char *str, char *base);
int		ft_toupper(int c);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

#endif