#include "libft.h"
#include "defines.h"
#include "signals.h"
#include "utils.h"

/* `<SUMMARY>`:
 * Creates a separate array of strings for faster
 * search later in the execution.
 * `<PARAM>`:
 * `env`: array of strings containing the env variables;
 * `<RETURN>`:
 * Freeable array of strings containing the PATH variables
 * Returns NULL on failure. */
static char	**create_bin_paths(char **env)
{
	while (NULL != *env && ft_strncmp(*env, "PATH=", 5))
		++env;
	if (NULL == *env)
		return (NULL);
	return (ft_split((*env) + 5, ':'));
}

/* `<SUMMARY>`:
 * Copies the environment array of strings given to the program
 * to a variable in the main struct.
 * `<PARAM>`:
 * `env`: array of strings containing the env variables;
 * `<RETURN>`:
 * Freeable array of strings containing the environment variables
 * Returns NULL on failure. */
static char	**copy_env(char **env)
{
	return (ft_arrdup((const char **)env));
}

/* `<SUMMARY>`:
 * Creates a default env when no envs are set.
 * `<PARAM>`:
 * `main`: main struct containing all other variables;
 * `env`: array of strings containing the env variables;
 * `<RETURN>`:
 * `TRUE` on success and `FALSE` on fail. */
static t_bool	create_own_environment(t_main *main)
{
	char	**own;
	char	*pwd;

	pwd = NULL;
	own = ft_calloc(4, sizeof(char *));
	pwd = getcwd(NULL, 0);
	if (NULL == pwd || NULL == own)
		return (free(pwd), free(own), FALSE);
	own[0] = ft_strdup("SHLVL=1");
	own[1] = ft_strjoin("PWD=", pwd);
	own[2] = ft_strdup("_=/usr/bin/env");
	main->env = own;
	set_env_arr(main->env);
	main->bin_path = NULL;
	main->user = NULL;
	free(pwd);
	return (TRUE);
}

t_bool	init_shell(t_main *main, char **env)
{
	set_exit_status(EXIT_SUCCESS);
	set_quit(NO_QUIT);
	main->stdin = dup(STDIN_FILENO);
	main->stdout = dup(STDOUT_FILENO);
	main->stderr = dup(STDERR_FILENO);
	main->pars_error = FALSE;
	if (ft_arrlen((const char **)env) != 0)
	{
		main->env = copy_env(env);
		set_env_arr(main->env);
		if (NULL == main->env)
			return (FALSE);
		main->user = getenv("USER");
		main->bin_path = create_bin_paths(env);
		set_bin_path(main->bin_path);
	}
	else
		create_own_environment(main);
	return (TRUE);
}
