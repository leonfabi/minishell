#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "defines.h"

typedef struct s_env	t_env;

struct s_env
{
	t_env	*next;
	char	*name;
	char	*value;
};

/*
 `<summary>`:
 Initializes the main struct from minishell.
 `<parameter>`:
 `main`: main struct containing all other variables;
 `env`: array of strings containing the env variables;
 `<returns>`:
 Returns `TRUE` on success and `FALSE` on fail.
*/
t_bool	init_shell(t_main *main, t_path env);

/*
 `<summary>`:
 Creates a default env when no envs are set.
 `<parameter>`:
 `main`: main struct containing all other variables;
 `env`: array of strings containing the env variables;
 `<returns>`:
 `TRUE` on success and `FALSE` on fail.
*/
t_bool	create_own_environment(t_main *main, t_path env);

/*
 `<summary>`:
 Creates a new entry for the env linked list.
 `<parameter>`:
 `value`: string that contains "name=value".
 `<returns>`:
 the newly created env entry.
*/
t_env	*new_env_entry(char *value);

/*
 `<summary>`:
 Appends a new env entry to the existing one.
 `<parameter>`:
 `top`: current start of the env list.
 `new`: newly created entry by `new_env_entry`.
 `<returns>`:
 `TRUE` on success and `FALSE` on fail.
*/
t_bool	append_variable(t_env *top, t_env *new);

/*
 `<summary>`:
 Copy the existing env variables to a linked list.
 `<parameter>`:
 `env`: array of strings containing the env variables;
 `<returns>`:
 the top of the env linked list.
*/
t_env	*copy_env(t_path env);

/*
 `<summary>`:
 Create an array of strings containing the binary paths.
 `<parameter>`:
 `env`: array of strings containing the env variables;
 `<returns>`:
 Array of strings containing the binary paths (t_path).
*/
t_path	create_bin_paths(t_path env);

#endif
