/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:01:47 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/30 18:38:56 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;

	if ((!s1 && !s2))
		return (0);
	i = 0;
	p_s1 = (const unsigned char *)s1;
	p_s2 = (const unsigned char *)s2;
	if (!p_s1)
		return (-p_s2[0]);
	if (!p_s2)
		return (p_s1[0]);
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
			return (p_s1[i] - p_s2[i]);
		i++;
	}
	return (0);
}
