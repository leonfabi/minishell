/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:38:56 by makurz            #+#    #+#             */
/*   Updated: 2023/09/21 10:56:10 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the length of the string 's'.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (NULL == s)
		return (NO_SIZE);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
