/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:14:24 by makurz            #+#    #+#             */
/*   Updated: 2023/09/05 17:42:56 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the first occurrence of the character 'c' in the string 's'
// within size 'n'.
char	*ft_strnchr(const char *s, size_t size, int c)
{
	while (*s && size > 0)
	{
		if (*s == (unsigned char) c)
			return ((char *)s);
		++s;
		--size;
	}
	return (NULL);
}
