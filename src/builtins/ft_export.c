#include "minishell.h"

/* `<summary>`:
 Checks if the given variable is a valid variable for
 an environment variable in our shell.
 `<parameter>`:
 `var`: string that represents the variable name;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail. */
static t_bool	precheck_env_update(char *var)
{
	t_bool	check;
	char	*run;

	run = var;
	check = TRUE;
	check &= ft_isalpha(*run) | ('_' == *run);
	while (check == TRUE && *(++run) != '\0' && *run != '=')
		check &= ft_isalnum(*run) | ('_' == *run);
	if (check == FALSE)
		printf("minishell: export: '%s': not a valid identifier\n", var);
	return (check);
}

static char	**append_env_variable(char **env, char *var)
{
	int		arrlen;
	char	**new_env;
	int		i;

	arrlen = ft_arrlen((const char **)env);
	new_env = ft_resize_array(env, arrlen, arrlen + 1);
	if (ft_strchr(var, '=') == NULL)
		new_env[arrlen] = ft_strjoin(var, "=");
	else
		new_env[arrlen] = ft_strdup(var);
	return (new_env);
}

static char	*replace_env_variable(char *env, char *var)
{
	if (ft_strncmp(env, var, ft_strlen_c(var, '=') + 1) != 0)
		return (env);
	free(env);
	return (ft_strdup(var));
}

static char	**update_env_variables(char **env, char *var)
{
	char	**upd;
	t_bool	check;
	t_bool	replace;
	size_t	len;

	check = precheck_env_update(var);
	replace = FALSE;
	if (check == FALSE)
		return (env);
	upd = env;
	len = ft_strlen_c(var, '=');
	while (NULL != *upd)
	{
		if (ft_strncmp(*upd, var, len) == 0)
		{
			replace = TRUE;
			break ;
		}
		++upd;
	}
	if (replace == TRUE)
		*upd = replace_env_variable(*upd, var);
	else
		env = append_env_variable(env, var);
	return (env);
}

int	ft_export(t_execcmd *cmd, char ***env)
{
	int		arrlen;
	int		i;

	i = 0;
	arrlen = ft_arrlen((const char **)cmd->argv);
	if (arrlen == 1)
		;;
		// FIX: export_print;
	while (++i < arrlen)
	{
		*env = update_env_variables(*env, cmd->argv[i]);
	}
	return (EXIT_SUCCESS);
}
