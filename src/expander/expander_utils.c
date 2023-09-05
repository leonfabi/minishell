#include "minishell.h"

char	*advance_and_copy(char **input, int size)
{
	char	*key;

	key = NULL;
	key = ft_strndup(*input, size);
	*input += size;
	return (key);
}

char	*expand_special(char *input)
{
	if (*input != '$')
		return (ft_strdup(input));
	if (*(input + 1) == '?')
		return (ft_itoa(*get_exit_status()));
	if (*(input + 1) == '0')
		return (ft_strdup("minishell"));
	if (*(input + 1) == '$')
		return (ft_itoa((int)getpid()));
	if (*(input + 1) == '\0')
		return (ft_strdup("$"));
	return (ft_strdup(""));
}

