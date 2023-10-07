#include "libft.h"
#include "defines.h"
#include "builtins.h"
#include "utils.h"
#include "signals.h"

t_bool	precheck_env_update(char **var)
{
	t_bool	check;
	char	*run;

	run = *var;
	check = TRUE;
	check &= ft_isalpha(*run) | ('_' == *run);
	while (check == TRUE && *(++run) != '\0' && *run != '=')
		check &= ft_isalnum(*run) | ('_' == *run);
	if (check == FALSE)
	{
		general_error("export", *var, ERR_ID);
		set_exit_status(EXIT_FAILURE);
	}
	if (ft_strchr(*var, '=') == NULL)
	{
		*var = ft_strjoinfree(*var, "=", 'L');
	}
	return (check);
}

void	declare_x(char **env)
{
	char	**copy;
	char	*tmp;
	char	**start;

	copy = ft_arrdup((const char **)env);
	start = copy;
	if (NULL == copy)
	{
		set_exit_status(EXIT_FAILURE);
		return ;
	}
	copy = sort_array(copy);
	while (*copy != NULL)
	{
		write(1, "declare -x ", 11);
		write(1, *copy, ft_strlen_c(*copy, '=') + 1);
		ft_fprintf(1, "\"%s\"\n", *copy + ft_strlen_c(*copy, '=') + 1);
		++copy;
	}
	ft_arrfree(start);
	set_exit_status(EXIT_SUCCESS);
}

char	**sort_array(char **arr)
{
	int		i;
	char	*tmp;
	int		k;
	int		size;

	i = -1;
	size = ft_arrlen((const char **)arr);
	while (++i < size - 1)
	{
		k = -1;
		while (++k < size - i - 1)
		{
			if (ft_strcmp(arr[k], arr[k + 1]) > 0)
			{
				tmp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = tmp;
			}
		}
	}
	return (arr);
}
