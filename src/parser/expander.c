#include "minishell.h"

static char	*check_for_expansion(char *env, char *name, int len)
{
	char	*sub;
	
	if (ft_strncmp(env, name, len) != 0)
		return (NULL);
	if (*(env + len) == '=')
		return (env + len + 1);
	return (NULL);
}

char	*expand_token(t_token *tok, char **env)
{
	char	*value;
	char	*sub;
	int		len;

	// TODO: WRITE function for getting multiple special
	// characters 
	// 1. Find amount of special characters
	// 2. Create strjoin to add them together
	// 3. Malloc each string
	value = tok->value;
	len = tok->value_length - 1;
	if (*value != '$' || tok->type == TOKEN_QUOTE)
		return (value);
	++value;
	while (NULL != *env)
	{
		sub = check_for_expansion(*env, value, len);
		if (NULL != sub)
		{
			return (sub);
		}
		++env;
	}
	return (value + len);
}