#include "builtins.h"
#include "defines.h"
#include "environment.h"
#include "libft.h"

t_bool	search_env_variable(t_env **update, char *name)
{
	if (NULL == *update)
		return (FALSE);
	if (ft_strcmp((*update)->name, name))
		return (TRUE);
	*update = (*update)->next;
	while (NULL != (*update)->next)
	{
		if (ft_strcmp((*update)->name, name))
			return (TRUE);
		(*update) = (*update)->next;
	}
	return (FALSE);
}

t_bool	precheck_env_update(char *variable)
{
	return (TRUE);
}

void	update_env_variable(t_env *update, char *variable, size_t len)
{
	free(update->value);
	update->value = NULL;
	update->value = ft_strdup((variable + (len + 1)));
}

t_bool	update_env_variables(t_env *head, char *variable)
{
	t_env	*update;
	size_t	var_length;

	update = head;
	var_length = ft_strlen_c(variable, '=');
	if ('\0' == *(variable + var_length))
		return (FALSE);
	if (search_env_variable(&update, ft_strndup(variable, var_length)) == TRUE)
		update_env_variable(update, variable, var_length);
	return (TRUE);
}
	// (*new) = (t_env){
	// 	.name = ft_strndup(value, name_len),
	// 	.value = ft_strdup((value + (name_len + 1))),
	// 	.next = NULL
	// };
	//
	//

/* TODO:
 * - add checks for invalid characters
 * - add testing for the env updates
 * - think about what else to add
 */
