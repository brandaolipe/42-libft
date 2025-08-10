/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:48:34 by febranda          #+#    #+#             */
/*   Updated: 2025/08/10 18:28:14 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c);
static char		*ft_get_word( char const *s, size_t end);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	array = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	j = 0;
	while (*s)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			while (s[i] && s[i] != c)
				i++;
			array[j++] = ft_get_word(s, i + 1);
			s += i;
		}
	}
	array[j] = NULL;
	return (array);
}

static char	*ft_get_word(char const *s, size_t size)
{
	char	*word;

	word = malloc(size);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, size);
	return (word);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			counter++;
		while (*s && *s != c)
			s++;
	}
	return (counter);
}
