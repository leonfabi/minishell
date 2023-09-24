#include "defines.h"
#include "utils.h"

char	***get_env_arr(void)
{
	static char	**env;

	return (&env);
}

void	set_env_arr(char **env)
{
	char	***env_arr;

	env_arr = get_env_arr();
	*env_arr = env;
}
