/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:37:27 by makurz            #+#    #+#             */
/*   Updated: 2023/06/04 13:32:29 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the char 'c' to the file descriptor 'fd'.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
