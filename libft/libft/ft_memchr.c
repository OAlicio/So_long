/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:33:49 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/25 19:39:36 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s;

	if (!s)
		return (NULL);
	i = 0;
	p_s = (unsigned char *)s;
	while (i < n && p_s)
	{
		if (*p_s == (unsigned char)c)
			return (p_s);
		i++;
		p_s++;
	}
	return (NULL);
}
