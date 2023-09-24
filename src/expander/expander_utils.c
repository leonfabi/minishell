#include "libft.h"
#include "defines.h"
#include "expander.h"
#include "signals.h"
#include "utils.h"

/* `<SUMMARY>`:
 * .Helper function for creating the key list for the expansion.
 *  Copies the key and advances the char pointer.
 * `<PARAM>`:
 * `input`: Pointer to the input string;
 * `size`: size of the key;
 * `<RETURN>`:
 * Returns a freeable copy of the key (`$` is being removed). */
static char	*advance_and_copy(char **input, int size)
{
	char	*key;

	key = NULL;
	key = ft_strndup(*input, size);
	*input += size;
	return (key);
}

/* `<SUMMARY>`:
 * .Function to extract the key from a given string.
 * Checks for `$` and decides accordingly.
 * `<PARAM>`:
 * `input`: Pointer to the input string;
 * `<RETURN>`:
 * Returns a freeable copy of the key (`$` is being removed). */
static char	*get_key(char **input)
{
	t_bool	check;
	char	*var;
	int		len;

	len = 1;
	var = *input;
	check = TRUE;
	if (**input != '$')
		return (advance_and_copy(input, ft_strlen_c(*input, '$')));
	if (*(var + 1) == '?')
		return (advance_and_copy(input, 2));
	if (ft_isdigit(*(var + 1)) == TRUE)
		return (advance_and_copy(input, 2));
	if (*(var + 1) == '$')
		return (advance_and_copy(input, 2));
	while (*(var + len) != '\0')
	{
		check &= ft_isalnum(*(var + len)) | ('_' == *(var + len));
		if (check == FALSE)
			break ;
		++len;
	}
	return (advance_and_copy(input, len));
}

t_list	*create_keylist(char *input)
{
	t_list	*start;
	char	*key;

	key = NULL;
	start = NULL;
	while ('\0' != *input)
	{
		key = get_key(&input);
		ft_lstadd_back(&start, ft_lstnew(key));
	}
	return (start);
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
		return (ft_strdup("not_implemented"));
		// return (ft_itoa((int)getpid()));
	if (*(input + 1) == '\0')
		return (ft_strdup("$"));
	return (ft_strdup(""));
}
