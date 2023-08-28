#include "minishell.h"

// FIX: memory leak when second element is unset
static t_bool	freeconnect(t_env **env)
{
	t_env	*delete;

	delete = (*env)->next;
	free(delete->name);
	delete->name = NULL;
	free(delete->value);
	delete->value = NULL;
	(*env)->next = delete->next;
	free(delete);
	delete = NULL;
	return (TRUE);
}

t_bool	ft_unset(t_env **env, char *var)
{
	t_env	*run;
	t_env	*curr;

	set_exit_status(EXIT_SUCCESS);
	if (*env != NULL && ft_strcmp((*env)->name, var) == 0)
		return (*env = (*env)->next, TRUE);
	run = (*env)->next;
	curr = (*env);
	while (NULL != run->next)
	{
		if (ft_strcmp(run->name, var) == 0)
		{
			freeconnect(&curr);
			break ;
		}
		run = run->next;
		curr = curr->next;
	}
	return (TRUE);
}
