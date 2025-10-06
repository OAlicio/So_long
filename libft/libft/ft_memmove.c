/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:34:36 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/02 12:28:48 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*to_src;
	char		*to_dest;

	if (!dest || !src)
		return (dest);
	to_dest = (char *)dest;
	to_src = (const char *)src;
	if (to_dest < to_src)
	{
		while (n--)
		{
			*to_dest++ = *to_src++;
		}
	}
	else if (to_dest > to_src)
	{
		to_dest += n - 1;
		to_src += n - 1;
		while (n--)
		{
			*to_dest-- = *to_src--;
		}
	}
	return (dest);
}
