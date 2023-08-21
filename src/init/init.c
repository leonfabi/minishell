#include "minishell.h"

t_bool	init_shell(t_main *main, t_path env)
{
	if (NULL != getenv("USER"))
	{
		main->env = copy_env(env);
		main->user = getenv("USER");
	}
	else
		create_own_environment(main, env);
	return (TRUE);
}

t_env	*copy_env(t_path env)
{
	int			i;
	t_env		*top;

	top = new_env_entry(*env++);
	while (NULL != *env)
		append_variable(top, new_env_entry(*env++));
	return (top);
}

t_bool	append_variable(t_env *top, t_env *new)
{
	t_env	*run;

	run = top;
	while (NULL != run->next)
		run = run->next;
	run->next = new;
	return (TRUE);
}

// TODO: create better error handling
t_env	*new_env_entry(char *value)
{
	t_env	*new;
	size_t	name_len;

	name_len = ft_strlen_c(value, '=');
	new = ft_calloc(1, sizeof(t_env));
	if (NULL == new)
		return (NULL);
	(*new) = (t_env){
		.name = ft_strndup(value, name_len),
		.value = ft_strdup((value + (name_len + 1))),
		.next = NULL
	};
	return (new);
}

// TODO: create better error handling
t_bool	create_own_environment(t_main *main, t_path env)
{
	t_env		*top;
	char		*pwd;

	(void)env;
	pwd = NULL;
	pwd = getcwd(pwd, PATH_MAX);
	if (NULL == pwd)
		return (FALSE);
	top = new_env_entry("SHLVL=1");
	append_variable(top, new_env_entry(ft_strjoin("PWD=", pwd)));
	append_variable(top, new_env_entry("_=/usr/bin/printenv"));
	main->bin_path = NULL;
	main->no_environment = TRUE;
	main->user = NULL;
	free(pwd);
	return (TRUE);
}

// void	print_env(t_env *env)
// {
// 	t_env	*run;
// 
// 	if (env == NULL)
// 		return ;
// 	run = env;
// 	while (NULL != run->next)
// 	{
// 		printf("%s=%s\n", run->name, run->value);
// 		run = run->next;
// 	}
// }

// int	main(int argc, char *argv[], char *env[])
// {
// 	// t_main		main;
// 
// 	char		*pwd;
// 
// 	pwd = NULL;
// 	pwd = getcwd(pwd, 0);
// 	printf("%s\n", pwd);
// 	// main = (t_main){};
// 	// init_shell(&main, env);
// 	// print_env(main.env);
// 	free(pwd);
// 	return (EXIT_SUCCESS);
// }
