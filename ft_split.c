/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:48:34 by febranda          #+#    #+#             */
/*   Updated: 2025/08/07 20:04:36 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_word_count(char const *s, char c);
static char	*ft_get_word(char const *s, int end);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	nb_words;
	size_t	i;
	size_t	j;

	if (!s || !c)
		return (NULL);
	nb_words = ft_word_count(s, c);
	array =(char **)malloc(nb_words + 1 * sizeof(char *));
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
			array[j++] = ft_get_word(s, i);
		}
	}
	array[j] = NULL;
	return (array);
}

static char	*ft_get_word(char const *s, int end)
{
	char	*word;

	word = malloc(end + 1);
	ft_strlcpy(word, s, end);
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

int     main(void)
{
  char c = ' ';
  char    str[] = "Lorem Ipsum is simply text of the printing";
  int     nb = ft_word_count(str, c);
  char	**str1;

str1 = ft_split(str, ' ');

int i = 0;
while (i < nb)
{
	printf("%s palavras\n", str1[i++]);
}
}
