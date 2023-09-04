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

// NOTE: EXAMPLE
// $$$?$0$
static t_bool	check_valid_expansion(char c)
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

static int	expansion_amount(t_token *tok)
{
	int		amount;
	char	*str;

	str = tok->value;
	amount = 0;
	while (tok->value_length-- > 1)
	{
		if (check_valid_expansion(*str))
			++amount;
		++str;
	}
	return (amount);
}

char	*expand_token(t_token *tok, char **env)
{
	char	*value;
	char	*sub;
	int		len;
	int		amount;

	if (tok->type == TOKEN_QUOTE)
		return (ft_strndup(tok->value, tok->value_length));
	amount = expansion_amount(tok);
	if (amount == 0)
		return (ft_strndup(tok->value, tok->value_length));
	value = tok->value;
	len = tok->value_length - 1;
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
