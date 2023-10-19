/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:51:31 by makurz            #+#    #+#             */
/*   Updated: 2023/09/21 14:48:07 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Concatenates 'dst' and 'src'.
// '\0'-terminates the result except for 'dst' being longer than dstsize.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int			i;
	size_t		dst_len;
	size_t		src_len;

	i = -1;
	if (NULL == dst || NULL == src)
		return (NO_SIZE);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (dstsize + src_len);
	if (dstsize > 0)
		dstsize--;
	while (src[++i] && dst_len + i < dstsize)
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
