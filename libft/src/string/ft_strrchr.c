/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:10:43 by makurz            #+#    #+#             */
/*   Updated: 2023/03/27 21:25:19 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the last occurrence of the character 'c' ind the string 's'.
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *) s + len;
	if (*ptr == (unsigned char) c)
		return (ptr);
	ptr--;
	while (len--)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
