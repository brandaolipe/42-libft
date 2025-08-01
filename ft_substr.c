/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:00:29 by febranda          #+#    #+#             */
/*   Updated: 2025/08/01 20:08:39 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_string;
	size_t		i;
	size_t		str_len;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	new_string = ft_calloc((len + 1), sizeof(char));
	i = 0;
	if (!new_string)
		return (NULL);
	if (len == 0)
		return (new_string);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ft_memcpy(new_string, s + start, len);
	return (new_string);
}
