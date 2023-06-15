/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:32:42 by lpeng             #+#    #+#             */
/*   Updated: 2023/05/11 15:32:59 by lpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	un_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = un_len((unsigned int)n);
	if (n == 0)
		len = 1;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (len);
}

/*#include <stdio.h>
int	main()
{
	int len = ft_putnbr(-256489);
	printf("len = %d", len);
	return (0);
}*/
