/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:58:30 by lpeng             #+#    #+#             */
/*   Updated: 2023/05/11 14:51:29 by lpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}*/

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, char c)
{
	int	len;

	len = hex_len(n);
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	if (n >= 10 && n < 16)
	{
		if (c == 'X')
			ft_putchar((n - 10) + 'A');
		else
			ft_putchar((n - 10) + 'a');
	}
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	return (len);
}

/*#include<stdio.h>
int	main()
{
	unsigned int n = 0;
	char c = 'X';
	int len = ft_puthex(n, c);
	int buildin = printf("%x", n);
	printf("\nlen = %d, buildin = %d", len, buildin);
	return (0);
}*/
