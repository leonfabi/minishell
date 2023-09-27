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
	// set_exit_status(sig);
	write(STDOUT_FILENO, "\n", 1);
	here_cleanup();
	exit(sig);
}
