/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:55:17 by makurz            #+#    #+#             */
/*   Updated: 2023/04/19 08:19:27 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the first occurrence of 'needle' in the string 'haystack'.
// Compares at most 'len' characters.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *) haystack);
	ptr = (char *) haystack;
	while (*ptr && len-- >= n_len)
	{
		if (*ptr == *needle && !ft_strncmp(ptr, needle, n_len))
			return (ptr);
		ptr++;
	}
	return (NULL);
}
