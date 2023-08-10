/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:21:26 by makurz            #+#    #+#             */
/*   Updated: 2023/08/10 16:32:54 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

typedef struct sigaction	t_signal;
typedef struct termios		t_termios;
typedef void				t_handler(int);


/*
 ** Main function for handling signals in minishell.
 ** Input parameter is a pointer to a t_termios struct
 ** to handle the control-characters.
 ** Located in signal_handling.c.
 */
int		user_signal_listener(t_termios *xterm);

/*
 ** Function to cleanup the control-character..
 ** Control-characters appear after pressing ctrl-c..
 ** Located in signal_handling.c.
 */
void	cleanup_control_character(t_termios *xterm);

void	termination_handler(int signum);

void	handle_quit_signal(void);

#endif // !SIGNALS_H
