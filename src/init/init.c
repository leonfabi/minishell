#include "minishell.h"

static char	**create_bin_paths(char **env)
{
	char	**bin_path;

	while (NULL != *env && ft_strncmp(*env, "PATH=", 5))
		++env;
	if (NULL == *env)
		return (NULL);
	bin_path = ft_split((*env) + 5, ':');
	if (NULL == bin_path)
		return (NULL);
	return (bin_path);
}

static char	**copy_env(char **env)
{
	return (ft_arrdup((const char **)env));
}

t_bool	init_shell(t_main *main, char **env)
{
	set_exit_status(EXIT_SUCCESS);
	if (NULL != env)
	{
		main->env = copy_env(env);
		if (NULL == main->env)
			return (FALSE);
		main->user = getenv("USER");
		main->bin_path = create_bin_paths(env);
	}
	else
		create_own_environment(main);
	return (TRUE);
}
// 
t_bool	create_own_environment(t_main *main)
{
	char	**own;
	char	*pwd;

	pwd = NULL;
	own = ft_calloc(4, sizeof(char *));
	pwd = getcwd(pwd, PATH_MAX);
	if (NULL == pwd || NULL == own)
		return (free(pwd), free(own), FALSE);
	own[0] = ft_strdup("SHLVL=1");
	own[1] = ft_strjoin("PWD=", pwd);
	own[2] = ft_strdup("_=/usr/bin/env");
	main->bin_path = NULL;
	main->user = NULL;
	free(pwd);
	return (TRUE);
}
