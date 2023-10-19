/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:37:10 by makurz            #+#    #+#             */
/*   Updated: 2023/03/27 13:54:37 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes 'n' bytes from 's' to 0.
// Usage of ft_memset.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
