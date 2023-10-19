/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:02:58 by makurz            #+#    #+#             */
/*   Updated: 2023/09/15 19:43:50 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies 'n' bytes from memory space 'src' to memory space 'dst'.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s = src;
	char		*d;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = (char *) dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}
