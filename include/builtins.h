#ifndef BUILTINS_H
# define BUILTINS_H

# include "defines.h"

typedef int	(*t_builtin_p)(t_execcmd *);

/* `<SUMMARY>`:
 * Builtin function to change the directory.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns `exit_code` respective to if the cd succeeded or failed. */
int		ft_cd(t_execcmd *cmd);

/* `<SUMMARY>`:
 * Function for printing out the `declare -x` lines alphabetically
 * sorted when export is given without any argument.
 * `<PARAM>`:
 * `env`: array of strings containing the environment variables;*/
void	declare_x(char **env);

/* `<SUMMARY>`:
 * Builtin function to print out the given arguments to STDOUT.
 * Possible flag is `-n` which removes the new line character
 * at the end of the line.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns `exit_code` respective to if cd succeeded or failed. */
int		ft_echo(t_execcmd *cmd);

/* `<SUMMARY>`:
 * Print all name and value pairs of the environment variable.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns `EXIT_SUCCESS` on success. */
int		ft_env(t_execcmd *cmd);

/* `<SUMMARY>`:
 * Function to exit the program with the given exit_code.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns the resulting `exit_code`. */
int		ft_exit(t_execcmd *cmd);

/* `<SUMMARY>`:
 * Function to export a `key=value` pair into the environment for the
 * current shell. If `key` already exists, it replaces the value of it.
 * If `key` does not exist, it will append the key=value pair to the
 * current environment array of strings. When export is given without
 * any arguments, export will call the `declare_x` function.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns the given `exit_code`. */
int		ft_export(t_execcmd *cmd);

/* `<SUMMARY>`:
 * Checks if the given variable is a valid variable for
 * an environment variable in our shell.
 * `<PARAM>`:
 * `var`: string that represents the variable name;
 * `<RETURN>`:
 * Returns `TRUE` on success and `FALSE` on fail. */
t_bool	precheck_env_update(char *var);

/* `<SUMMARY>`:
 * Small helper function to easily print a single string to a given
 * file descriptor. Does not append a new line automatically.
 * `<PARAM>`:
 * `fd`: file descriptor to write to;
 * `str`: string to print;
 * `<RETURN>`:
 * Returns the amount of written bytes. */
int		print(int fd, char *str);

/* `<SUMMARY>`:
 * Prints out the current working directory.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns `exit_code` respective to if pwd succeeded or failed. */
int		ft_pwd(t_execcmd *cmd);

/* `<SUMMARY>`:
 * Helper function for `declare_x` to sort the array of strings of the
 * environment alphabetically before printing it out..
 * `<PARAM>`:
 * `arr`: array of strings;
 * `<RETURN>`:
 * Returns the sorted array of strings. */
char	**sort_array(char **arr);

/* `<SUMMARY>`:
 * Removes the corresponding var from the environment variables.
 * `<PARAM>`:
 * `cmd`: execute node of the AST;
 * `<RETURN>`:
 * Returns the exit status of the unset function (always true)*/
int		ft_unset(t_execcmd *cmd);

#endif
