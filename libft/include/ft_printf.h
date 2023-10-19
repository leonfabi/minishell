/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:45:06 by makurz            #+#    #+#             */
/*   Updated: 2023/09/09 00:01:22 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// include the necessary libraries
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// define bases for hex and dec
# define DEC "0123456789"
# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"
# define TRUE 1
# define FALSE 0

// Name all the prototypes
int		ft_fprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
int		f_putchar(char c, int *printed);
int		f_putstr(char *s, int *printed);
size_t	ft_strlen(const char *s);
int		ft_putnbr(long nbr, int *printed);
int		ft_putunbr(unsigned int nbr, int *printed);
int		ft_putnbrbase(size_t nb, char *base, int *printed);
int		ft_putptr(void *ptr, int *printed);

#endif
