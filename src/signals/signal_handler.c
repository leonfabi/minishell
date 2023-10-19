/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:49:51 by makurz            #+#    #+#             */
/*   Updated: 2023/10/19 11:32:35 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "signals.h"
#include "utils.h"

#define RED_PROMPT "\e[m\e[0;31m❯ \e[m"

void	termination_handler(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_set_prompt(RED_PROMPT);
	rl_on_new_line();
	rl_redisplay();
	set_exit_status(128 + signum);
}

void	universal_handler(int sig, t_handler *handler)
{
	t_signal	action;

	sigemptyset(&action.sa_mask);
	action = (t_signal){
		.sa_handler = handler,
		.sa_flags = SA_RESTART | SA_SIGINFO
	};
	sigaction(sig, &action, NULL);
}

int	user_signal_listener(t_termios *xterm)
{
	cleanup_control_character(xterm);
	universal_handler(SIGINT, termination_handler);
	universal_handler(SIGQUIT, SIG_IGN);
	return (EXIT_SUCCESS);
}
