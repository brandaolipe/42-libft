/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:52 by febranda          #+#    #+#             */
/*   Updated: 2025/07/29 19:18:59 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len < size - 1)
		return (dest_len + src_len);
	if (size < dest_len)
		return (size + src_len);
	while (*src != '\0' && dest_len < size - 1)
	{
		dest[dest_len] = *src;
		src++;
		dest_len++;
	}
	*(dest + dest_len) = '\0';
	return (dest_len + src_len);
}

//Concatena strings
//dst precisa ter pelo menos um byte libre.
//um byte para NUL deve ser incluído em size.
//As duas src e dst devem ser strings verdadeiras terminadas em NUL.
//

//Retorna o comprimento total da string que ela tentou criar, 
// ou seja o comprimento de src.
