/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:43:55 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/08 10:42:51 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putunbr(unsigned int n, int i)
{
	char	digit;

	if (n >= 10)
		i = ft_putunbr(n / 10, i);
	i++;
	digit = '0' + (n % 10);
	write(1, &digit, 1);
	return (i);
}

int	ft_putnbr(int n, int i)
{
	char	digit;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb >= 10)
		i = ft_putnbr(nb / 10, i);
	i++;
	digit = '0' + (nb % 10);
	write(1, &digit, 1);
	return (i);
}

int	ft_puthnbr(unsigned int n, char *hex, int i)
{
	if (n > 15)
		i = ft_puthnbr(n / 16, hex, i);
	i++;
	write(1, &hex[n % 16], 1);
	return (i);
}

int	ft_putpnbr(uintptr_t n, char *hex, int i)
{
	if (n > 15)
		i = ft_putpnbr(n / 16, hex, i);
	i++;
	write(1, &hex[n % 16], 1);
	return (i);
}
