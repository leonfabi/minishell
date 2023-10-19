/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:03:03 by makurz            #+#    #+#             */
/*   Updated: 2023/09/04 22:20:04 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy a string and returning a pointer to its end
char	*ft_stpcpy(char *dst, const char *src)
{
	size_t		len;

	len = ft_strlen(src);
	return (ft_memcpy(dst, src, len + 1) + len);
}
