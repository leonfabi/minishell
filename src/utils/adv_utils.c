/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:49:59 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:49:59 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "utils.h"

void	adv_free(char **to_free)
{
	if (NULL == to_free)
		return ;
	free(*to_free);
	*to_free = NULL;
}

pid_t	adv_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		general_error("forking", "could not fork the process", NULL);
	return (pid);
}
