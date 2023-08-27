#include "minishell.h"

int	env(t_env *env)
{
	t_env		*run;

	run = env;
	while (run->next != NULL)
	{
		if (NULL != run->value)
			printf("%s=%s\n", run->name, run->value);
		run = run->next;
	}
	set_exit_status(0);
	return (TRUE);
}
