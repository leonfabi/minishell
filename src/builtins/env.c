#include "minishell.h"

int	env(t_env *env)
{
	t_env		*run;

	run = env;
	while (env->next != NULL)
	{
		if (NULL != env->value)
			printf("%s=%s\n", env->name, env->value);
		run = run->next;
	}
	set_exit_status(0);
	return (TRUE);
}
