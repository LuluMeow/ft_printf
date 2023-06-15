/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:10:40 by lpeng             #+#    #+#             */
/*   Updated: 2023/05/11 15:31:21 by lpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_conversion(va_list args, char c);
int		ft_printf(const char *placeholders, ...);
int		ft_putunsigned(unsigned int n);
int		hex_len(unsigned int n);
int		ft_puthex(unsigned int n, char c);
int		ft_putptr(unsigned long n);
int		un_len(unsigned int n);
int		ptr_len(uintptr_t n);
int		ft_putptr(uintptr_t n);
void	ft_ptrhex(uintptr_t n);

#endif
