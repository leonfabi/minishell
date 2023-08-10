#include "minishell.h"
#include <criterion/criterion.h>

Test(simple, sigint)
{
	signal(SIGINT, termination_handler);
	raise(SIGINT);
}

Test(simple, sigquit)
{
	signal(SIGQUIT, SIG_IGN);
	raise(SIGQUIT);
}
