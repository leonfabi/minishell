/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:47:23 by makurz            #+#    #+#             */
/*   Updated: 2023/04/18 22:24:10 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int c)
{
	if (c == '-')
		return (-1);
	return (1);
}

// Converts a string to an int.
// Arbitrary amount of leading white spaces, optional plus/minus sign.
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = ft_sign(str[i++]);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}
	return (result * sign);
}
