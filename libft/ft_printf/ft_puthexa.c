/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:25:58 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/08 10:42:42 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	put_hl(va_list args)
{
	int		i;
	int		n;
	char	*hex;

	n = 0;
	i = va_arg(args, unsigned int);
	hex = ft_strdup("0123456789abcdef");
	n = ft_puthnbr(i, hex, n);
	free(hex);
	return (n);
}

int	put_hu(va_list args)
{
	int		i;
	int		n;
	char	*hex;

	n = 0;
	i = va_arg(args, unsigned int);
	hex = ft_strdup("0123456789ABCDEF");
	n = ft_puthnbr(i, hex, n);
	free(hex);
	return (n);
}

int	put_p(va_list args)
{
	uintptr_t	i;
	int			n;
	char		*hex;

	n = 0;
	i = va_arg(args, uintptr_t);
	if (!i)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = ft_strdup("0123456789abcdef");
	write(1, "0x", 2);
	n = ft_putpnbr(i, hex, n);
	n += 2;
	free(hex);
	return (n);
}
