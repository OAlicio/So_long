/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:38:30 by ofeverei          #+#    #+#             */
/*   Updated: 2025/06/25 20:10:05 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_word(const char *s, size_t start, size_t end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	fill_split(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[j] = get_word(s, start, i);
			if (!res[j])
				return (free_all(res, j), 0);
			j++;
		}
	}
	res[j] = NULL;
	return (1);
}

static int	splitcounter(char const *s, char c)
{
	size_t	char_count;
	size_t	in_word;

	char_count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			char_count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (char_count);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = splitcounter(s, c);
	res = malloc((wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!fill_split(res, s, c))
		return (NULL);
	return (res);
}
