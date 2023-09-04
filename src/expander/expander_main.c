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

static t_bool	check_valid_expansion(char c, char n)
{
	if (c == '-')
		return (TRUE);
	if (c == '$')
		return (TRUE);
	if (c == '?')
		return (TRUE);
	if (ft_isalnum(c) == TRUE)
		return (TRUE);
	return (FALSE);
}

static int	expansion_amount(t_token *tok, int *amount)
{
	char	*str;
	t_bool	check;

	check = TRUE;
	str = tok->value;
	*amount = 0;
	while (tok->value_length-- > 1)
	{
		if (check_valid_expansion(*str, *(str + 1)))
			++amount;
		++str;
	}
	return (*amount);
}

char	*search_environment(char **env)
{
	while (NULL != *env)
	{
		ft_strlcat(sub, check_for_expansion(*env, value, len), 10000);
		sub = check_for_expansion(*env, value, len);
		if (NULL != sub)
		{
			return (sub);
		}
		++env;
	}
}

// TODO: use strlcat with strlen + 1
// start with the empty string and call strdup at the end of the function
char	*expand_token(t_token *tok, char **env)
{
	char	*value;
	char	sub[10000];
	int		len;
	int		amount;

	ft_bzero(sub, 10000);
	if (tok->type == TOKEN_QUOTE)
		return (ft_strndup(tok->value, tok->value_length));
	if (expansion_amount(tok, &amount) == 0)
		return (ft_strndup(tok->value, tok->value_length));
	value = tok->value;
	len = tok->value_length - 1;
	++value;
	return (value + len);
}

// Handles $$, $?, $-, and $VARIABLE
// char	*expand_token(t_token *tok, char **env)
// {
// 	char	*value;
// 	char	*sub;
// 	int		len;
// 	int		amount;
// 
// 	if (tok->type == TOKEN_QUOTE)
// 		return (ft_strndup(tok->value, tok->value_length));
// 	if (expansion_amount(tok, &amount) == 0)
// 		return (ft_strndup(tok->value, tok->value_length));
// 	value = tok->value;
// 	len = tok->value_length - 1;
// 	++value;
// 	while (NULL != *env)
// 	{
// 		sub = check_for_expansion(*env, value, len);
// 		if (NULL != sub)
// 		{
// 			return (sub);
// 		}
// 		++env;
// 	}
// 	return (value + len);
// }
