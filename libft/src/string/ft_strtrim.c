/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:28:50 by makurz            #+#    #+#             */
/*   Updated: 2023/04/16 11:25:05 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a freeable copy of the string 's1.
// The start and end are trimmed with the characters from 'set'.
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_isinstr(s1[start], set) && s1[start])
		++start;
	while (ft_isinstr(s1[end], set) && end > start)
		--end;
	trim = ft_substr(s1, start, end + 1 - start);
	return (trim);
}
