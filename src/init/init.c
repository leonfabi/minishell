#include "minishell.h"

t_bool	create_own_environment(t_main *main, t_env env)
{
	main->bin_path = NULL;
	main->no_environment = TRUE;


	return (TRUE);
}

t_bool	init_shell(t_main *main, t_env env)
{
	if (NULL == getenv("USER"))
		create_own_environment(main, env);
	return (TRUE);
}
