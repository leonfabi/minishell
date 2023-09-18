#include "signals.h"

/* `<SUMMARY>`:
 Function to cleanup the control-character.
 Control-characters appear after pressing ctrl-c.
 `<PARAM>`:
 `xterm`: t_termios struct of current terminaL.
 Located in signal_handling.c. */
static void	cleanup_control_character(t_termios *xterm)
{
	t_termios	local_termios;

	if (tcgetattr(STDOUT_FILENO, xterm) == -1)
	{
		ft_fprintf(2, "minishell: cleanup: %s\n", strerror(errno));
		return ;
	}
	if (tcgetattr(STDOUT_FILENO, &local_termios) == -1)
	{
		ft_fprintf(2, "minishell: cleanup: %s\n", strerror(errno));
		return ;
	}
	local_termios.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &local_termios);
}

static void	handle_childs()
{
	while (waitpid(-1, NULL, WNOHANG) > 0);
}

/* `<SUMMARY>`:
 Function for handling the SIGINT signal. SIGINT represents
 the signal provoked by pressing ctrl+c and the exit code 130.
 `<PARAM>`:
 `signum`integer represents the signal to handle.
 Located in signal_handling.c. */
static void	termination_handler(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	set_exit_status(128 + signum);
}

static void	universal_handler(int sig, t_handler *handler)
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
	universal_handler(SIGCHLD, handle_childs);
	universal_handler(SIGQUIT, SIG_IGN);
	return (EXIT_SUCCESS);
}
