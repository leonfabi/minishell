/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:19:58 by makurz            #+#    #+#             */
/*   Updated: 2023/04/16 13:01:09 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the first occurrence of 'needle' in the string 'haystack'.
char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	size_t	n_len;
	size_t	h_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *) haystack);
	h_len = ft_strlen(haystack);
	ptr = (char *) haystack;
	while (*ptr && h_len-- >= n_len)
	{
		if (*ptr == *needle && !ft_strncmp(ptr, needle, n_len))
			return (ptr);
		ptr++;
	}
	return (NULL);
}
