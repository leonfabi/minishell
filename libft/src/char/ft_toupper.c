/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:24:36 by makurz            #+#    #+#             */
/*   Updated: 2023/04/16 00:17:12 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts lowercase characters to uppercase characters.
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
