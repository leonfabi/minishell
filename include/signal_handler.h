#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include "defines.h"
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
 Main function for handling signals in minishell.
 Input parameter is a pointer to a t_termios struct
 to handle the control-characters.
 Located in signal_handling.c.
 */
int		user_signal_listener(t_termios *xterm);

/*
 Function to cleanup the control-character..
 Control-characters appear after pressing ctrl-c..
 Located in signal_handling.c.
 */
void	cleanup_control_character(t_termios *xterm);

/*
 Function for handling the SIGINT signal. SIGINT represents
 the signal provoked by pressing ctrl+c and the exit code 130.
 The input parameter `signum` represents the signal.
 */
void	termination_handler(int signum);

#endif // !SIGNALS_H
