#include "minishell.h"

int	env(t_env *env)
{
	t_env		*run;

	run = env;
	while (env->next != NULL)
	{
		printf("%s=%s\n", env->name, env->value);
		run = run->next;
	}
	set_exit_code(0);
	return (TRUE)
}