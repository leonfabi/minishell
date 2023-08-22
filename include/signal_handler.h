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
`xterm`: t_termios struct of current terminaL.
`Return`: EXIT_SUCCESS on success.
 */
int		user_signal_listener(t_termios *xterm);

/*
Function to cleanup the control-character..
Control-characters appear after pressing ctrl-c..
`xterm`: t_termios struct of current terminaL.
Located in signal_handling.c.
 */
void	cleanup_control_character(t_termios *xterm);

/*
Function for handling the SIGINT signal. SIGINT represents
the signal provoked by pressing ctrl+c and the exit code 130.
`signum`: Integer representing the signal to handle.
Located in signal_handling.c.
 */
void	termination_handler(int signum);

/*
Get the current exit status to correctly display it.
`Return`: Address to a static variable.
Located in signal_handling.c.
*/
int	*get_exit_status(void);

/*
Set the current exit status.
`status`: Integer for setting the exit status according to the execution.
Located in signal_handling.c.
*/
void	set_exit_status(int status);

#endif // !SIGNALS_H
