/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:07:26 by makurz            #+#    #+#             */
/*   Updated: 2023/04/18 22:06:46 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the str 's' to the file descriptor 'fd'.
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
