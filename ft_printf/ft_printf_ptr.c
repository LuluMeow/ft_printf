/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:58:30 by lpeng             #+#    #+#             */
/*   Updated: 2023/05/11 15:31:58 by lpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}*/

int	ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_putptr(uintptr_t n)
{
	int		len;

	len = 0;
	len += ft_putstr("0x");
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		ft_ptrhex(n);
		len += ptr_len(n);
	}
	return (len);
}

void	ft_ptrhex(uintptr_t n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	if (n >= 10 && n < 16)
		ft_putchar((n - 10) + 'a');
	if (n >= 16)
	{
		ft_ptrhex(n / 16);
		ft_ptrhex(n % 16);
	}
}

/*#include<stdio.h>
int	main()
{
	unsigned int n = 572;
	char c = 'X';
	int len = ft_puthex(n, c);
	printf("\nlen = %d", len);
	return (0);
}*/
