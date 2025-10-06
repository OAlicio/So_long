/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:44:31 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/18 15:48:33 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_join(char const *src, char *dest, size_t len);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*f_string;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	f_string = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!f_string)
		return (NULL);
	ft_join(s1, f_string, 0);
	ft_join(s2, f_string, len_s1);
	f_string[len_s1 + len_s2] = '\0';
	return (f_string);
}

static	void	ft_join(char const *src, char *dest, size_t start)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[start + i] = src[i];
		i++;
	}
}
