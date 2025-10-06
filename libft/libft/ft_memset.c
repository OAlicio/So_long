/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:25:01 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/26 14:04:45 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	val;

	if (!s)
		return (s);
	i = 0;
	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	while (i < n)
	{
		ptr[i] = val;
		i++;
	}
	return (s);
}
