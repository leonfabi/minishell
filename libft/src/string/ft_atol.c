/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work </var/mail/work>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:39:17 by work              #+#    #+#             */
/*   Updated: 2023/05/31 09:41:00 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int c)
{
	if (c == '-')
		return (-1);
	return (1);
}

// Converts a string to a long.
// Arbitrary amount of leading white spaces, optional plus/minus sign.
long	ft_atol(const char *str)
{
	int		i;
	long	result;
	int		sign;

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
	return (result * (long) sign);
}
