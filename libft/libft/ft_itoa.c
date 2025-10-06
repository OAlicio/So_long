/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:45:38 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/18 15:36:49 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n);
static void	fill_string(long n, char *strn, int sign, int i);
static void	reverse_string(char *strn, int length);
static int	is_neg(long n);

char	*ft_itoa(int n)
{
	int		digits;
	int		sign;
	char	*strn;
	long	nb;

	nb = n;
	sign = is_neg(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		nb = -nb;
	digits = count_digits(nb);
	strn = ft_calloc(digits + sign + 1, sizeof(char));
	if (!strn)
		return (NULL);
	if (sign)
		strn[0] = '-';
	fill_string(nb, strn, sign, digits);
	reverse_string(strn + sign, digits);
	strn[digits + sign] = '\0';
	return (strn);
}

static int	count_digits(long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	fill_string(long n, char *strn, int sign, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		strn[sign + j] = '0' + n % 10;
		n /= 10;
		j++;
	}
}

static void	reverse_string(char *strn, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = strn[start];
		strn[start] = strn[end];
		strn[end] = temp;
		start++;
		end--;
	}
}

static int	is_neg(long n)
{
	return (n < 0);
}
