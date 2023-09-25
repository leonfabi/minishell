#include "libft.h"
#include "defines.h"
#include "environment.h"
#include "utils.h"

/* `<SUMMARY>`:
 * Updates the PWD and OLDPWD environment variable after changing the
 * directory.
 * `<PARAM>`:
 * `sh`: main struct containing the environment variable array of strings;
 * `<RETURN>`:
 * Nothing. */
void	update_pwd(t_main *sh)
{
	char	*update;

	update = NULL;
	update = ft_strjoinfree("OLDPWD=", get_env(sh->env, "PWD"), 'R');
	sh->env = update_env_variables(sh, update);
	free(update);
	update = NULL;
	update = ft_strjoinfree("PWD=", getcwd(NULL, 0), 'R');
	sh->env = update_env_variables(sh, update);
	free(update);
}

char	*get_env(char **env, char *search)
{
	size_t	len;

	len = ft_strlen(search);
	while (NULL != *env)
	{
		if (ft_strncmp(*env, search, len) == 0 && *(*env + len) == '=')
			return (ft_strdup((*env) + len + 1));
		++env;
	}
	return (NULL);
}

char	**update_bin_path(t_main *sh, char *update)
{
	char	**bin_path;

	ft_arrfree(sh->bin_path);
	if (update == NULL)
		return (NULL);
	bin_path = ft_split(update, ':');
	set_bin_path(bin_path);
	return (bin_path);
}

t_bool	check_env_variable(char *env, char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (ft_strncmp(env, name, len) != 0)
		return (FALSE);
	if (*(env + len) == '=')
		return (TRUE);
	return (FALSE);
}
