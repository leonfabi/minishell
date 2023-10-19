/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:24:46 by makurz            #+#    #+#             */
/*   Updated: 2023/09/05 10:10:01 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a freeable string 'dst', which is concatenated from 's1' and 's2'.
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = ft_calloc(dstsize, sizeof(*dst));
	if (NULL == dst)
		return (NULL);
	dst = ft_strcpy(dst, s1);
	ft_strlcat(dst, s2, dstsize);
	return (dst);
}
