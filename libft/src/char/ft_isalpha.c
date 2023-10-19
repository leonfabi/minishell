/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:35:19 by makurz            #+#    #+#             */
/*   Updated: 2023/04/16 12:40:42 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if 'c' is an alphabetic character.
int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (1);
	return (0);
}
