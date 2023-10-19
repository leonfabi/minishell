/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:43:05 by makurz            #+#    #+#             */
/*   Updated: 2023/03/27 21:10:39 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Searches 'n' bytes in 's' for 'c' returning the first occurrence.
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
	{
		if (*str == (unsigned char) c)
			return (str);
		str++;
	}
	return (NULL);
}
