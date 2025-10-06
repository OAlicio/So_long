/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:11:25 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/14 12:55:50 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print(const char *fmt, va_list args)
{
	int	j;

	j = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (ft_verify(fmt))
				j += ft_type(fmt, args);
			else
			{
				write(1, "%", 1);
				write(1, fmt, 1);
				return (-1);
			}
		}
		else
		{
			write(1, fmt, 1);
			j++;
		}
		fmt++;
	}
	return (j);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		j;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	j = ft_print(fmt, args);
	va_end(args);
	return (j);
}
