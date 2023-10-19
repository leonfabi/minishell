/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:48:32 by makurz            #+#    #+#             */
/*   Updated: 2023/04/19 08:20:24 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a substring from 's' from the 'start' location with length 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(s);
	if (size < start)
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	dst = (char *) ft_calloc((len + 1), sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
