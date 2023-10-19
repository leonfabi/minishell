/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:55:38 by makurz            #+#    #+#             */
/*   Updated: 2023/08/19 15:16:06 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a freeable copy of the string 's1' with at most 'n' bytes copied.
char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*copy;

	len = ft_strnlen(s1, n);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, len);
	copy[len] = '\0';
	return (copy);
}
