/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:13:47 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/25 19:46:17 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*to_dest;
	const unsigned char	*to_src;

	if (!dest || !src)
		return (dest);
	to_dest = (unsigned char *)dest;
	to_src = (const unsigned char *)src;
	while (n--)
		*(to_dest++) = *(to_src++);
	return (dest);
}
