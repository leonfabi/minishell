#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "defines.h"

/* `<SUMMARY>`:
 * Initializes the main struct from minishell.
 * `<PARAM>`:
 * `main`: main struct containing all other variables;
 * `env`: array of strings containing the env variables;
 * `<RETURN>`:
 * Returns `TRUE` on success and `FALSE` on fail. */
t_bool	init_shell(t_main *main, char **env);

/* `<SUMMARY>`:
 * Checks if the variable `name` is a variable in the
 * environment array of strings.
 * `<PARAM>`:
 * `env`: string member of the array of strings of the environment;
 * `name`: variable name to check against;
 * `<RETURN>`:
 * `TRUE` on success and `FALSE` on fail. */
t_bool	check_env_variable(char *env, char *name);

/* `<SUMMARY>`:
 * Gets the variable `search` from the environment variables.
 * `<PARAM>`:
 * `env`: string member of the array of strings of the environment;
 * `search`: variable name to search for;
 * `<RETURN>`:
 * Freeable string of the found string or `NULL`. */
char	*get_env(char **env, char *search);

/* `<SUMMARY>`:
 * Updates the environment array of strings in the main sh struct
 * with the given `var`. If found, it will replace it, else it will
 * append the string to the array.
 * `<PARAM>`:
 * `sh`: main struct containing also the environment;
 * `var`: variable to update the environment with;
 * `<RETURN>`:
 * Updated environment array of strings. */
char	**update_env_variables(t_main *sh, char *var);

#endif
