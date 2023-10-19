/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:18:11 by makurz            #+#    #+#             */
/*   Updated: 2023/04/16 00:16:30 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts uppercase characters to lowercase characters.
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
