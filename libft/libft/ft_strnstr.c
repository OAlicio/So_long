/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:14:36 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/26 16:24:22 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_search(const char *big,
				const char *little, size_t i, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*val;

	i = 0;
	if (!little || little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			val = ft_search(big, little, i, len);
			if (val)
				return (val);
		}
		i++;
	}
	return (NULL);
}

static char	*ft_search(const char *big,
		const char *little, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (little[j] != '\0' && (i + j) < len)
	{
		if (big[i + j] != little[j])
			return (NULL);
		j++;
	}
	if (little[j] == '\0')
		return ((char *)big + i);
	return (NULL);
}
