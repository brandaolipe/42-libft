/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:00:58 by febranda          #+#    #+#             */
/*   Updated: 2025/07/31 19:38:21 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nmenb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= (nmenb * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
