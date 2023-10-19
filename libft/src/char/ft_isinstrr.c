/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinstrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <dumba@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:47:45 by makurz            #+#    #+#             */
/*   Updated: 2023/04/20 10:54:43 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// input a string, a char and an index
// it searches if the char is in the string from the index
// to the start of the string
int	ft_isinstrr(int c, const char *str, int i)
{
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return (1);
		--i;
	}
	return (0);
}
