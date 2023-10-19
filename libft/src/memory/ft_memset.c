/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:48:00 by makurz            #+#    #+#             */
/*   Updated: 2023/04/18 22:18:14 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sets 'len' bytes from 'b' to 'c'.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;

	dst = (unsigned char *) b;
	while (len--)
		*dst++ = (unsigned char) c;
	return (b);
}
