#include <signal.h>
#include <criterion/criterion.h>
#include "minishell.h"

void crash(void);

Test(simple, caught, .signal = SIGINT)
{
	handle_termination_signal();
	raise(SIGINT);
}

Test(simple, ignore, .signal = SIGQUIT)
{
	handle_quit_signal();
	raise(SIGQUIT);
}
