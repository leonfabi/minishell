/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:59:20 by makurz            #+#    #+#             */
/*   Updated: 2023/09/21 10:55:54 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	if (NULL == s)
		return (NO_SIZE);
	while (maxlen != 0 && s[i] != '\0')
	{
		++i;
		--maxlen;
	}
	return (i);
}
