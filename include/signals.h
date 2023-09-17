#ifndef SIGNALS_H
# define SIGNALS_H

# include "defines.h"

/* `<SUMMARY>`:
 * Main function for handling signals in minishell.
 * `<PARAM>`:
 * `xterm`: t_termios struct of current terminaL.
 * `<RETURN>`:
 *  EXIT_SUCCESS on success.
 * Located in signal_handling.c. */
int		user_signal_listener(t_termios *xterm);

/* `<SUMMARY>`:
 * Get the current exit status to correctly display it.
 * `<RETURN>`:
 * Address to a static variable.
 * Located in exit_status.c. */
int		*get_exit_status(void);

/* `<SUMMARY>`:
 * Set the current exit status.
 * `<PARAM>`:
 * `status` integer for setting the exit status according to the execution.
 * Located in exit_status.c. */
void	set_exit_status(int status);

/* `<SUMMARY>`:
 * Checks if the child exited normally or was terminated
 * due to an unhandled signal. According to which is the case,
 * the exit status is set.
 * `<PARAM>`:
 * `status` status received by the waitpid() command.
 * Located in exit_status.c. */
void	child_exit_status(int status);

/* `<SUMMARY>`:
 * Get the current last child pid.
 * `<RETURN>`:
 * Address to a static variable holding the last child pid.
 * Located in exit_status.c. */
int		*get_child_pid(void);

/* `<SUMMARY>`:
 * Set the current child pid.
 * `<PARAM>`:
 * `pid` integer for setting the current last child pid.
 * Located in exit_status.c. */
void	set_child_pid(int pid);

#endif // !SIGNALS_H
