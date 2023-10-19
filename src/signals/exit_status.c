/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:49:47 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 10:49:48 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "signals.h"

int	*get_exit_status(void)
{
	static int	status;

	return (&status);
}

void	set_exit_status(int status)
{
	int		*exit_status;

	exit_status = get_exit_status();
	*exit_status = status;
}

void	child_exit_status(int status)
{
	if (WIFEXITED(status))
		set_exit_status(WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		set_exit_status(WTERMSIG(status));
}

t_quit	*get_quit(void)
{
	static t_quit	quit;

	return (&quit);
}

void	set_quit(t_quit quit_status)
{
	t_quit	*quit;

	quit = get_quit();
	*quit = quit_status;
}
