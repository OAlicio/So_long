/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:00:17 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/08 10:42:14 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_verify(const char *c)
{
	if (*c == 'd' || *c == 'i')
		return (1);
	else if (*c == 'u')
		return (1);
	else if (*c == 'c')
		return (1);
	else if (*c == 's')
		return (1);
	else if (*c == 'x')
		return (1);
	else if (*c == 'X')
		return (1);
	else if (*c == 'p')
		return (1);
	else if (*c == '%')
		return (1);
	else
		return (0);
}

int	ft_type(const char *c, va_list args)
{
	if (*c == 'd' || *c == 'i')
		return (put_d(args));
	else if (*c == 'u')
		return (put_u(args));
	else if (*c == 'c')
		return (put_c(args));
	else if (*c == 's')
		return (put_s(args));
	else if (*c == 'x')
		return (put_hl(args));
	else if (*c == 'X')
		return (put_hu(args));
	else if (*c == 'p')
		return (put_p(args));
	else if (*c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (0);
}
