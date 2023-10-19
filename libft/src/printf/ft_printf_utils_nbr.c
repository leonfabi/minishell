/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:24:00 by makurz            #+#    #+#             */
/*   Updated: 2023/04/21 13:38:33 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes the number and base and recursively prints out the number.
int	ft_putnbrbase(size_t nb, char *base, int *printed)
{
	size_t	size;
	int		check;

	check = TRUE;
	size = ft_strlen(base);
	if (nb >= size)
	{
		check &= ft_putnbrbase(nb / size, base, printed);
		check &= ft_putnbrbase(nb % size, base, printed);
	}
	else if (nb < size)
		check &= f_putchar(base[nb], printed);
	return (check);
}

int	ft_putnbr(long nbr, int *printed)
{
	int		check;

	check = TRUE;
	if (nbr < 0)
	{
		check &= f_putchar('-', printed);
		nbr *= -1;
	}
	check &= ft_putnbrbase(nbr, DEC, printed);
	return (check);
}

int	ft_putunbr(unsigned int nbr, int *printed)
{
	return (ft_putnbrbase(nbr, DEC, printed));
}

// Prints '0x' in front of the then to hexadecimal converted number.
int	ft_putptr(void *ptr, int *printed)
{
	size_t		ui;
	int			check;

	check = TRUE;
	if (ptr != NULL)
	{
		ui = (size_t) ptr;
		check &= f_putstr("0x", printed);
		check &= ft_putnbrbase(ui, LHEX, printed);
	}
	else
		check &= f_putstr("0x0", printed);
	return (check);
}
