/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:15:29 by makurz            #+#    #+#             */
/*   Updated: 2023/08/09 18:39:18 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"
#include <stdlib.h>

int	signal_handling(t_termios *xterm)
{
	cleanup_control_character(xterm);
	handle_termination_signal();
	handle_quit_signal();
	return (EXIT_SUCCESS);
}

void	cleanup_control_character(t_termios *xterm)
{
	t_termios	local_termios;

	tcgetattr(STDOUT_FILENO, xterm);
	tcgetattr(STDOUT_FILENO, &local_termios);
	local_termios.c_lflag &= ~ECHOCTL;
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &local_termios);
}

int	handle_termination_signal(void)
{
	t_signal	sa;

	sa = (t_signal){
		.sa_flags = SA_RESTART,
			.sa_handler = termination_handler
	};
	sigemptyset(&sa.sa_mask);
	return (EXIT_SUCCESS);
}

void	termination_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	handle_quit_signal(void)
{
	t_signal	sa;

	sa = (t_signal){
		.sa_flags = SA_RESTART,
		.sa_handler = SIG_IGN
	};
	sigemptyset(&sa.sa_mask);
	return (EXIT_SUCCESS);
}
