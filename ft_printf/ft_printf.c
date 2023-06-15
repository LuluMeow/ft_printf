/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:33:54 by lpeng             #+#    #+#             */
/*   Updated: 2023/05/11 15:17:38 by lpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_conversion(va_list args, char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		counter += ft_putptr(va_arg(args, uintptr_t));
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		counter += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		counter += ft_puthex((va_arg(args, unsigned int)), c);
	else if (c == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, placeholders);
	i = 0;
	len = 0;
	while (placeholders[i])
	{
		if (placeholders[i] == '%')
		{
			len += ft_conversion(args, placeholders[i + 1]);
			i++;
		}
		else
			len += ft_putchar(placeholders[i]);
		i++;
	}
	va_end(args);
	return (len);
}
