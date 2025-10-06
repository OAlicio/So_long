/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:29:06 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/25 19:41:00 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	tot_size;
	void	*alloc;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((nmemb > (((size_t)-1) / size)))
		return (NULL);
	tot_size = nmemb * size;
	alloc = malloc(tot_size);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < tot_size)
	{
		((unsigned char *)alloc)[i] = 0;
		i++;
	}
	return (alloc);
}
