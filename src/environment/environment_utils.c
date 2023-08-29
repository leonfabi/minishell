#include "minishell.h"


void	free_env_list(t_env **env)
{
	t_env	*tmp;

	if (NULL == env)
		return ;
	tmp = (*env)->next;
	free((*env)->name);
	free((*env)->value);
	free(*env);
	*env = NULL;
	while (NULL != tmp)
	{
		*env = tmp;
		tmp = tmp->next;
		free((*env)->name);
		free((*env)->value);
		free(*env);
	}
}
