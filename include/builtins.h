#ifndef BUILTINS_H
# define BUILTINS_H

#include "environment.h"

int	echo(char **arg);
int	pwd(char **args);
int	print(int fd, char *str);

/* `<summary>`:
 Print all name and value pairs of the environment variable.
 `<parameter>`:
 `env`: array of strings containing the env variables;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail. */
t_bool	env(char **env);

/* `<summary>`:
 Removes the corresponding var from the environment variables.
 `<parameter>`:
 `env`: array of strings containing the env variables;
 `var`: the given name to be removed;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail. */
t_bool	ft_unset(char **env, char *name);

/* `<summary>`:
 Checks if the given variable is a valid variable for
 an environment variable in our shell.
 `<parameter>`:
 `var`: string that represents the variable name;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail. */
t_bool	precheck_env_update(char *var);

#endif
