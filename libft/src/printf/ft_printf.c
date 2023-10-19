/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:53 by makurz            #+#    #+#             */
/*   Updated: 2023/09/09 09:02:15 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function parses the specifier and calls the relevant function.
static int	ft_parse_specifier(char c, va_list args, int *printed)
{
	int		check;

	check = TRUE;
	if (c == 'c')
		check &= f_putchar(va_arg(args, int), printed);
	else if (c == 's')
		check &= f_putstr(va_arg(args, char *), printed);
	else if (c == 'p')
		check &= ft_putptr(va_arg(args, void *), printed);
	else if (c == 'i' || c == 'd')
		check &= ft_putnbr((long) va_arg(args, int), printed);
	else if (c == 'u')
		check &= ft_putunbr(va_arg(args, unsigned int), printed);
	else if (c == 'x')
		check &= ft_putnbrbase(va_arg(args, unsigned int), LHEX, printed);
	else if (c == 'X')
		check &= ft_putnbrbase(va_arg(args, unsigned int), UHEX, printed);
	else if (c == '%')
		check &= f_putchar('%', printed);
	return (check);
}

/* `<SUMMARY>`
 * Writes a formatted string to STDOUT_FILENO.
 * Can handle %c, %s, %d, %i, %p, %u, %x, and %X as as identifier.
 * `<PARAM>`
 * `format`: The format string, with specifiers (e.g. %s).
 * `...`: Additional string arguments to format.
 * `<RETURN>`
 * Number of characters printed; does not handle write errors. */
int	ft_printf(const char *format, ...)
{
	int		printed;
	int		check;
	int		i;
	va_list	args;

	printed = 0;
	i = -1;
	check = TRUE;
	va_start(args, format);
	if (!format)
		return (0);
	while (format[++i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		if (format[i] != '%')
			check &= f_putchar(format[i], &printed);
		else if (format[i++] == '%')
			check &= ft_parse_specifier(format[i], args, &printed);
		if (check == FALSE)
			return (-1);
	}
	va_end(args);
	return (printed);
}

/* `<SUMMARY>`
 * Writes a formatted string to the given file descriptor.
 * Can only handle %s as identifier.
 * `<PARAM>`
 * `fd`: The file descriptor to write to.
 * `format`: The format string, with %s specifiers.
 * `...`: Additional string arguments to format.
 * `<RETURN>`
 * Number of characters printed; does not handle write errors. */
int	ft_fprintf(int fd, const char *format, ...)
{
	int		printed;
	char	*str;
	va_list	args;

	printed = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (*format != '\0')
	{
		printed += write(fd, format, ft_strlen_c(format, '%'));
		format += ft_strlen_c(format, '%');
		if (*format == '%' && *(format + 1) == 's')
		{
			str = va_arg(args, char *);
			printed += write(fd, str, ft_strlen(str));
			format += 2;
		}
		else if (*format == '%')
			write(fd, format++, 1);
	}
	va_end(args);
	return (printed);
}
