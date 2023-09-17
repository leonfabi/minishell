#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	*get_child_pid(void)
{
	static pid_t	child_pid;

	return (&child_pid);
}

void	set_child_pid(int pid)
{
	pid_t	*child_pid;
	child_pid = get_child_pid();
	*child_pid = pid;
}

void handle_sigchld(int sig, siginfo_t *sip, void *context) {
	(void)sig;
	(void)context;
	(void)sip;  // We don't use this in the handler in this example

	// Reap all exited children (this won't block)
	while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main() {
	// Install the signal handler
	pid_t	child;
	struct sigaction sa;
	sa.sa_sigaction = handle_sigchld;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;

	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	// Fork some child processes
	for (int i = 0; i < 4; ++i) {
		child = fork();
		set_child_pid(child);
		printf("Current child: %d\n", child);
		if (child == 0) {
			// Simulate some work with sleep
			sleep(1 + i);
			exit(i);  // Exit with a code
		}
	}

	// Wait specifically for the last child to exit
	int status;
	pid_t last_child_pid = waitpid(*get_child_pid(), &status, 0);  // This will block
	int exit_code = WEXITSTATUS(status);
	printf("Last child with PID %d exited with status %d\n", last_child_pid, exit_code);

	// Give some time for the signal handler to reap other children
	// sleep(10);

	return 0;
}
