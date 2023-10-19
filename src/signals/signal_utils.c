/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:49:54 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 11:31:32 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "signals.h"
#include "executor.h"
#include "utils.h"

void	cleanup_control_character(t_termios *xterm)
{
	t_termios	local_termios;

	if (tcgetattr(STDOUT_FILENO, xterm) == -1)
	{
		general_error("cleanup", strerror(errno), NULL);
		return ;
	}
	if (tcgetattr(STDOUT_FILENO, &local_termios) == -1)
	{
		general_error("cleanup", strerror(errno), NULL);
		return ;
	}
	local_termios.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &local_termios);
}

void	exit_heredoc(int sig)
{
	int	fd;

	sig += 128;
	fd = *get_close_fd();
	if (fd != STDIN_FILENO || fd != STDOUT_FILENO)
		close(fd);
	set_exit_status(sig);
	write(STDOUT_FILENO, "\n", 1);
	here_cleanup();
	exit(sig);
}

void	wait_user_signals(void)
{
	universal_handler(SIGINT, termination_handler);
	universal_handler(SIGQUIT, SIG_IGN);
}

void	block_parent_handler(void)
{
	universal_handler(SIGINT, SIG_IGN);
	universal_handler(SIGQUIT, SIG_IGN);
}

void	heredoc_child_handler(void)
{
	universal_handler(SIGINT, exit_heredoc);
	universal_handler(SIGQUIT, SIG_IGN);
}
