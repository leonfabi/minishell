/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:25:05 by makurz            #+#    #+#             */
/*   Updated: 2023/09/21 22:19:55 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a freeable copy of the string 's1'.
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1) + 1;
	dst = malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, len);
	return (dst);
}
