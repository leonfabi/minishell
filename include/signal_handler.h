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

/* `<summary>`:
 Define structs to use a shorter version in the code
 for more readability and structure. */
typedef struct sigaction	t_signal;
typedef struct termios		t_termios;
typedef void				t_handler(int);

/* `<summary>`:
 Main function for handling signals in minishell.
 `<parameter>`:
 `xterm`: t_termios struct of current terminaL.
 `<returns>`:
  EXIT_SUCCESS on success.
 Located in signal_handling.c. */
int		user_signal_listener(t_termios *xterm);

/* `<summary>`:
 Function to cleanup the control-character.
 Control-characters appear after pressing ctrl-c.
 `<parameter>`:
 `xterm`: t_termios struct of current terminaL.
 Located in signal_handling.c. */
void	cleanup_control_character(t_termios *xterm);

/* `<summary>`:
 Function for handling the SIGINT signal. SIGINT represents
 the signal provoked by pressing ctrl+c and the exit code 130.
 `<parameter>`:
 `signum`integer represents the signal to handle.
 Located in signal_handling.c. */
void	termination_handler(int signum);

/* `<summary>`:
 Get the current exit status to correctly display it.
 `<returns>`:
 Address to a static variable.
 Located in exit_status.c. */
int		*get_exit_status(void);

/* `<summary>`:
 Set the current exit status.
 `<parameter>`:
 `status` integer for setting the exit status according to the execution.
 Located in exit_status.c. */
void	set_exit_status(int status);

#endif // !SIGNALS_H
