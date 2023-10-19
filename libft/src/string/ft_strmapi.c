/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:11:50 by makurz            #+#    #+#             */
/*   Updated: 2023/04/19 08:18:41 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a new string 'ptr'.
// The function 'f' is applied to every character + index of the string 's'.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*ptr;

	size = ft_strlen(s);
	ptr = (char *) malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[size] = '\0';
	while (size--)
		ptr[size] = (*f)((unsigned int) size, s[size]);
	return (ptr);
}
