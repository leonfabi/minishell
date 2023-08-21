#include "minishell.h"

t_bool	create_own_environment(t_main *main, t_path env)
{
	main->bin_path = NULL;
	main->no_environment = TRUE;

	return (TRUE);
}

// char	*get_env_value(char *value)
// {
// 	char	*new;

// 	if (NULL == value)
// 		return (ft_strdup(""));
	
// 	return (new);
// }
t_env	*new_env_entry(char *value)
{
	t_env	*new;
	size_t	name_len;

	name_len = ft_strlen_c(value, '=');
	new = ft_calloc(1, sizeof(t_env));
	if (NULL == new)
		return (NULL); // more sophisticated error handling
	*new = (t_env){
		.name = ft_strndup(value, name_len),
		.value = ft_strdup((value + (name_len + 1))),
		.next = NULL
	};
	return (new);
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

t_env	*copy_env(t_path env)
{
	int			i;
	t_env		*top;

	while (NULL != *env)
		append_variable(top, new_env_entry(*env++));
	return (top);
}

t_bool	init_shell(t_main *main, t_path env)
{
	if (NULL != getenv("USER"))
		main->env = copy_env(env);
	else
		create_own_environment(main, env);

	return (TRUE);
}
