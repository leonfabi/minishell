/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:21:18 by makurz            #+#    #+#             */
/*   Updated: 2023/04/18 22:07:06 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the string 's' to the file descriptor 'fd', followed by a new line.
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	ft_putchar_fd('\n', fd);
}
