#include "libft.h"
#include "defines.h"
#include "environment.h"
#include "expander.h"
#include "utils.h"

/* `<SUMMARY>`:
 * Searches the whole environment for the given `name` to try to
 * expand it.
 * `<PARAM>`:
 * `tok`: token to get expanded;
 * `env`: array of strings of the environment variables;
 * `<RETURN>`:
 * Returns a freeable string with the expanded token. */
static char	*check_whole_env(char **env, char *name)
{
	char	**check;

	if (*name != '$')
		return (ft_strdup(name));
	check = env;
	while (NULL != *check)
	{
		if (check_env_variable(*check, name + 1) == TRUE)
			return (ft_strdup(*check + ft_strlen_c(*check, '=') + 1));
		++check;
	}
	return (ft_strdup(""));
}

/* `<SUMMARY>`:
 * Main function for expanding a string of the given input. It will
 * run through the key list and appends each expanded or non expanded
 * string to the current string. Key is getting expanded if it starts
 * with a `$` and is not a TOKEN_QUOTE.
 * `<PARAM>`:
 * `run`: linked list of keys to expand;
 * `env`: array of strings of the environment variables;
 * `<RETURN>`:
 * Returns a freeable string with the expanded keys. */
static char	*create_expanded_string(t_list *run, char **env)
{
	char	*expand;
	char	*add;
	char	*key;

	expand = ft_strdup("");
	while (run)
	{
		key = run->content;
		if (ft_strlen(key) <= 2)
			add = expand_special(key);
		else
			add = check_whole_env(env, key);
		expand = ft_strjoinfree(expand, add, 'B');
		key = NULL;
		run = run->next;
	}
	return (expand);
}

char	*expand_token(t_token *tok, char **env)
{
	char	*input;
	int		amount;
	t_list	*keylist;
	char	*expand;

	input = ft_strndup(tok->value, tok->len);
	if (tok->type == TOKEN_QUOTE)
		return (input);
	keylist = create_keylist(input);
	expand = create_expanded_string(keylist, env);
	adv_free(&input);
	ft_lstclear(&keylist, &free);
	return (expand);
}
