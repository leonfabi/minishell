/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:49:48 by makurz            #+#    #+#             */
/*   Updated: 2023/04/29 11:13:29 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates enough space for 'count' objects with 'size' bytes.
// The allocated memory is filled with value zero.
void	*ft_calloc(size_t count, size_t size)
{
	void	*buf;
	size_t	shield;

	shield = count * size;
	if ((size != 0) && (shield / size != count))
		return (NULL);
	buf = malloc(size * count);
	if (buf == NULL)
		return (NULL);
	ft_bzero(buf, size * count);
	return (buf);
}
