/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:34:20 by anaszanane        #+#    #+#             */
/*   Updated: 2021/12/23 09:47:33 by azanane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char	*str, ...);
void	ft_putchar(char c, int	*ct2);
void	ft_putstr(char	*s, int	*ct2);
void	ft_putnbr_base(int n, int b, char	*base, int	*ct2);
void	ft_putnbr(int n, int	*ct2);
void	ft_putunbr(unsigned int n, int	*ct2);
void	ft_putunbrbase(unsigned int n, unsigned int b, char	*base, int	*ct2);
void	ft_putadd(unsigned long long n, char	*base, int	*ct2);

#endif