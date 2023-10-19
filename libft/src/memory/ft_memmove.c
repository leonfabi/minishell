/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:31:24 by makurz            #+#    #+#             */
/*   Updated: 2023/04/18 22:16:58 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies 'n' bytes from memory space 'src' to memory space 'dst'.
// Memory may overlap.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	dst_tmp = (unsigned char *) dst;
	src_tmp = (const unsigned char *) src;
	if (dst < src)
	{
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	if (src < dst)
	{
		dst_tmp += len - 1;
		src_tmp += len - 1;
		while (len--)
			*dst_tmp-- = *src_tmp--;
	}
	return (dst);
}
