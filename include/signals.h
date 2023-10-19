#ifndef SIGNALS_H
# define SIGNALS_H

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
 * Function to cleanup the control-character.
 * Control-characters appear after pressing ctrl-c.
 * `<PARAM>`:
 * `xterm`: t_termios struct of current terminal.
 * Located in signal_handling.c. */
void	cleanup_control_character(t_termios *xterm);

/* `<SUMMARY>`:
 * Function to handle signals during heredoc execution..
 * `<PARAM>`:
 * `sig`: signal number. */
void	exit_heredoc(int sig);

/* `<SUMMARY>`:
 * Generic function to invoke signal handler with the default
 * presets..
 * `<PARAM>`:
 * `sig`: integer represents the signal to handle.
 * `handler`: pointer to the handler function.
 * Located in signal_handling.c. */
void	universal_handler(int sig, t_handler *handler);

/* `<SUMMARY>`:
 * Function for handling the SIGINT signal. SIGINT represents
 * the signal provoked by pressing ctrl+c and the exit code 130.
 * `<PARAM>`:
 * `signum`: integer represents the signal to handle.
 * Located in signal_handling.c. */
void	termination_handler(int signum);

/* `<SUMMARY>`:
 * Function for handling the SIGINT signal. SIGINT represents
 * the signal provoked by pressing ctrl+c and the exit code 130.
 * `<PARAM>`:
 * `signum`: integer represents the signal to handle.
 * Located in signal_handling.c. */
void	block_parent_handler(void);

/* `<SUMMARY>`:
 * Function for handling the SIGINT signal. SIGINT represents
 * the signal provoked by pressing ctrl+c and the exit code 130.
 * `<PARAM>`:
 * `signum`: integer represents the signal to handle.
 * Located in signal_handling.c. */
void	heredoc_child_handler(void);

/* `<SUMMARY>`:
 * Function for handling the SIGINT signal. SIGINT represents
 * the signal provoked by pressing ctrl+c and the exit code 130.
 * `<PARAM>`:
 * `signum`: integer represents the signal to handle.
 * Located in signal_handling.c. */
void	wait_user_signals(void);

#endif // !SIGNALS_H
