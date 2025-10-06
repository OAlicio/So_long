/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:14:18 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/22 19:13:37 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <inttypes.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(const char *fmt, ...);
int		ft_putunbr(unsigned int n, int i);
int		ft_putnbr(int n, int i);
int		ft_puthnbr(unsigned int n, char *hex, int i);
int		ft_putpnbr(uintptr_t n, char *hex, int i);
int		ft_type(const char *c, va_list args);
int		ft_verify(const char *c);
int		ft_write(const char *c);
int		put_d(va_list args);
int		put_u(va_list args);
int		put_c(va_list args);
int		put_s(va_list args);
int		put_hl(va_list args);
int		put_hu(va_list args);
int		put_p(va_list args);

#endif
