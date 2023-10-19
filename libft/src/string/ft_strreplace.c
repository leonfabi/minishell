/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:33:07 by makurz            #+#    #+#             */
/*   Updated: 2023/09/13 13:59:18 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* `<SUMMARY>`
 * Takes a freeable string as target and replaces it
 * with a newly allocated string from `new_str`.
 * `<PARAM>`
 * `target`: freeable string to be replaced.
 * `new_str`: string that is getting copied to target.
 * `<RETURN>`
 * Pointer to the newly allocated string. */
char	*ft_strreplace(char *target, char *new_str)
{
	if (NULL == new_str || NULL == target)
		return (NULL);
	free(target);
	target = NULL;
	target = ft_strdup(new_str);
	return (target);
}
