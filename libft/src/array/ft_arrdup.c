/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:24:05 by makurz            #+#    #+#             */
/*   Updated: 2023/09/08 23:36:25 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* `<SUMMARY>`
 * Function for deep copying an array of strings to a new variable.
 * `<PARAM>`
 * `src`: input array of string.
 * `<RETURN>`
 * Returns a freeable array of string with the same size and values
 * as `src`.*/
char	**ft_arrdup(const char **src)
{
	int		i;
	size_t	size;
	char	**dst;

	if (src == NULL)
		return (NULL);
	size = ft_arrlen(src) + 1;
	i = -1;
	dst = ft_calloc(size, sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	while (src[++i])
		dst[i] = ft_strdup(src[i]);
	return (dst);
}
