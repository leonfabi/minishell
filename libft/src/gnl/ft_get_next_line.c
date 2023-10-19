/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:13:31 by makurz            #+#    #+#             */
/*   Updated: 2023/09/15 19:44:47 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Main function body of get_next_line
// First 'if' statement checks for valid inputs
// While loop is there for creating the new new_line
// and also filling the stash for keeping string after the new_line
char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	t_gnl		next;

	next = (t_gnl){};
	next.new_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (stash[0] != '\0' || read(fd, stash, BUFFER_SIZE) > 0)
	{
		next.new_line = ft_strjoin_gnl(next.new_line, stash, next);
		if (next.new_line == NULL)
			return (NULL);
		if (ft_clean_stash(stash, next) == true)
			break ;
		if (read(fd, stash, 0) < 0)
			return (free(next.new_line), NULL);
	}
	return (next.new_line);
}
