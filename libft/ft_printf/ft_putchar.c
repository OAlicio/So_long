/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:41:02 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/08 10:42:33 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	put_c(va_list args)
{
	int		n;
	char	i;

	n = 0;
	i = (char)va_arg(args, int);
	write(1, &i, 1);
	n++;
	return (n);
}

int	put_d(va_list args)
{
	int	i;
	int	n;

	n = 0;
	i = va_arg(args, int);
	n = ft_putnbr(i, n);
	return (n);
}

int	put_u(va_list args)
{
	unsigned int	i;
	int				n;

	n = 0;
	i = va_arg(args, unsigned int);
	n = ft_putunbr(i, n);
	return (n);
}

int	put_s(va_list args)
{
	int		i;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
