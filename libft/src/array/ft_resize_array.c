/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:05:12 by makurz            #+#    #+#             */
/*   Updated: 2023/09/21 11:14:44 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* `<SUMMARY>
 * Takes an array of strings and creates a new array of strings
 * with a new capacity and copies the old src to the new array
 * and freeing the src pointer afterwards.
 * `<PARAM>`
 * `src`: array of strings to copy.
 * `size`: length of the old array of strings.
 * `capacity`: length of the new array of strings.
 * `<RETURN>`
 * Returns the newly created array of strings with the old 
 * strings assigned to it and the new length of `capacity`. */
char	**ft_resize_array(char **src, size_t size, size_t capacity)
{
	size_t	i;
	char	**new_array;

	if (src == NULL)
		return (NULL);
	if (capacity < size)
	{
		ft_fprintf(2, "Capacity has to be at least `size`.");
		return (src);
	}
	i = 0;
	new_array = ft_calloc(capacity + 1, sizeof(*new_array));
	if (new_array == NULL)
		return (NULL);
	while (i < size)
	{
		new_array[i] = src[i];
		++i;
	}
	free(src);
	return (new_array);
}
