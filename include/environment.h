#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

/* `<SUMMARY>`:
 * Initializes the main struct from minishell. Copies stdin,
 * stdout, and stderr for restoring them after redirections.
 * Also, if there is no environment, init_shell will be creating
 * a minimal working environment like bash would.
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
char	**update_env_variables(t_main *sh, char **var);

/* `<SUMMARY>`:
 * Updates the PWD and OLDPWD environment variable after changing the
 * directory.
 * `<PARAM>`:
 * `sh`: main struct containing the environment variable array of strings;
 * `<RETURN>`:
 * Nothing. */
void	update_pwd(t_main *sh);

/* `<SUMMARY>`:
 * Update the bin path after unset or export is called with PATH as an
 * argument..
 * `<PARAM>`:
 * `sh`: main struct containing the environment variable array of strings;
 * `update`: string with which the bin_path is getting updated;
 * `<RETURN>`:
 * Freeable array of strings with the updated PATH, NULL after unset. */
char	**update_bin_path(t_main *sh, char *update);

#endif
