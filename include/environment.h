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
Initializes the main struct from minishell.
Input parameters are:
`main`: main struct containing all other variables;
`env`: array of strings containing the env variables;
Returns `TRUE` on success and `FALSE` on fail.
*/
t_bool	init_shell(t_main *main, t_path env);

/*
Creates a default env when no envs are set.
Input parameters are:
`main`: main struct containing all other variables;
`env`: array of strings containing the env variables;
Returns `TRUE` on success and `FALSE` on fail.
*/
t_bool	create_own_environment(t_main *main, t_path env);

/*
Creates a new entry for the env linked list.
Input parameter is:
`value`: string that contains "name=value".
Returns the newly created env entry.
*/
t_env	*new_env_entry(char *value);

/*
Appends a new env entry to the existing one.
Input parameters are:
`top`: current start of the env list.
`new`: newly created entry by `new_env_entry`.
Returns `TRUE` on success and `FALSE` on fail.
*/
t_bool	append_variable(t_env *top, t_env *new);

/*
Copy the existing env variables to a linked list.
Input parameter is:
`env`: array of strings containing the env variables;
Returns the top of the env linked list.
*/
t_env	*copy_env(t_path env);

#endif
