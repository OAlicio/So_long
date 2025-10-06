/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:18:16 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/18 15:27:49 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	s_size;
	char	*s_dup;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	s_dup = (char *)malloc((s_size + 1) * sizeof(char));
	if (!s_dup)
		return (NULL);
	i = 0;
	while (i < s_size)
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
