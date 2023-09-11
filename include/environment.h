#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "defines.h"

/* `<summary>`:
 Initializes the main struct from minishell.
 `<parameter>`:
 `main`: main struct containing all other variables;
 `env`: array of strings containing the env variables;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail. */
t_bool	init_shell(t_main *main, char **env);

/* `<summary>`:
 Creates a default env when no envs are set.
 `<parameter>`:
 `main`: main struct containing all other variables;
 `env`: array of strings containing the env variables;
 `<returns>`:
 `TRUE` on success and `FALSE` on fail. */
t_bool	create_own_environment(t_main *main);

/* `<summary>`:
Checks if the variable `name` is a variable in the
environment array of strings.
 `<parameter>`:
 `env`: string member of the array of strings of the environment;
 `name`: variable name to check against;
 `<returns>`:
 `TRUE` on success and `FALSE` on fail. */
t_bool	check_env_variable(char *env, char *name);

char	*get_env(char **env, char *search);

char	**update_env_variables(t_main *sh, char *var);

#endif
