/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:58:52 by makurz            #+#    #+#             */
/*   Updated: 2023/09/05 17:28:29 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the first occurrence of the character 'c' in the string 's'.
char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		++ptr;
	}
	if (*ptr == (unsigned char) c)
		return (ptr);
	return (NULL);
}
