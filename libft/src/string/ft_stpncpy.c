/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:25:03 by makurz            #+#    #+#             */
/*   Updated: 2023/09/05 10:10:39 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpncpy(char *dst, const char *src, size_t n)
{
	size_t		size;

	size = ft_strnlen(src, n);
	ft_memcpy(dst, src, n);
	dst += size;
	if (n == size)
		return (dst);
	return (ft_memset(dst, '\0', n - size));
}
