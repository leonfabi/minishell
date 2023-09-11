#include "minishell.h"

// FIX: Not needed anymore;

// t_bool	nulterminate(t_dlist **token)
// {
// 	t_dlist		*run;
// 	t_token		*tok;
// 
// 	run = *token;
// 	while (get_token_type(run) != TOKEN_EOF)
// 	{
// 		tok = get_token(run);
// 		if (correct_token(tok->type) == TRUE)
// 			*(tok->value + tok->len) = '\0';
// 		run = run->next;
// 	}
// 	return (TRUE);
// }
