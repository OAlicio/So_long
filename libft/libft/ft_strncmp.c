/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:09:15 by ofeverei          #+#    #+#             */
/*   Updated: 2025/07/04 15:44:55 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	if (s1 == NULL)
		return (-(unsigned char)s2[0]);
	if (s2 == NULL)
		return ((unsigned char)s1[0]);
	i = 0;
	while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
