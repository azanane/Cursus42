/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azanane <azanane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:34:20 by anaszanane        #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/22 23:00:53 by anaszanane       ###   ########.fr       */
=======
/*   Updated: 2021/12/23 09:47:33 by azanane          ###   ########.fr       */
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4
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
<<<<<<< HEAD
void	ft_putnbr_base(int n, int	b, const char	*str, int	*ct2);
void	ft_putnbr(int n, int	*ct2);
void	ft_putstr_hexa(char	*s, int	*ct2);
=======
void	ft_putnbr_base(int n, int b, char	*base, int	*ct2);
void	ft_putnbr(int n, int	*ct2);
void	ft_putunbr(unsigned int n, int	*ct2);
void	ft_putunbrbase(unsigned int n, unsigned int b, char	*base, int	*ct2);
void	ft_putadd(unsigned long long n, char	*base, int	*ct2);
>>>>>>> 0fe4981db4020f37bff9e4f103f67ffe6f4a09a4

#endif