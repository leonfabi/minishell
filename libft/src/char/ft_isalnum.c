/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:00:08 by makurz            #+#    #+#             */
/*   Updated: 2023/03/27 13:57:37 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if 'c' is either a decimal digit (0-9) or an alphabetic character.
int	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (1);
	if (ft_isalpha(c))
		return (1);
	return (0);
}
