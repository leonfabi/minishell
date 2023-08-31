#include "minishell.h"

#include <fcntl.h>

t_bool	check_redirect(t_type type)
{
	if (type == TOKEN_LESS)
		return (TRUE);
	if (type == TOKEN_GREATER)
		return (TRUE);
	if (type == TOKEN_DGREATER)
		return (TRUE);
	return (FALSE);
}

t_bool	check_arguments(t_type type)
{
	if (type == TOKEN_WORD)
		return (TRUE);
	if (type == TOKEN_DQUOTE)
		return (TRUE);
	if (type == TOKEN_QUOTE)
		return (TRUE);
	return (FALSE);
}

t_bool	check_metachars(t_type type)
{
	if (type == TOKEN_PIPE)
		return (TRUE);
	return (FALSE);
}

char	*get_token_value(t_dlist *token)
{
	t_token		*tok;

	tok = (t_token *)token->content;
	return (tok->value);
}

t_type	get_token_type(t_dlist *token)
{
	t_token		*tok;

	tok = (t_token *)token->content;
	return (tok->type);
}

t_cmd	*select_redirect(t_cmd *subcmd, t_token *tok)
{
	if (tok->type == TOKEN_LESS)
		return (redircmd(subcmd, tok, O_RDONLY, 0));
	if (tok->type == TOKEN_GREATER)
		return (redircmd(subcmd, tok, O_WRONLY | O_RDONLY, 1));
	if (tok->type == TOKEN_DGREATER)
		return (redircmd(subcmd, tok, O_WRONLY | O_CREAT, 1));
	// here we have to find something for the heredoc
	return (NULL);
}

t_cmd	*parse_redirect(t_cmd *cmd, t_dlist **token)
{
	t_dlist		*run;

	run = *token;
	while (check_redirect(get_token_type(run)) == TRUE)
	{
		if (check_arguments(get_token_type(run->next)) != FALSE)
			perror("missing file"); // get exit here
		cmd = select_redirect(cmd, get_token(run->next));
		run = run->next->next;
		if (NULL == run)
			perror("add something about EOF");
	}
	return (cmd);
}

t_cmd	*parse_execution(t_dlist **token)
{
	int			argc;
	t_dlist		*run;
	t_execcmd	*cmd;
	t_cmd		*ret;

	ret = execcmd();
	cmd = (t_execcmd *)ret;
	ret = parse_redirect(ret, token);
	run = *token;
	while (check_metachars(get_token_type(run)) == FALSE)
	{
		if (get_token_type(run) == TOKEN_EOF)
			break ;
		if (get_token_type(run) != TOKEN_WORD) // add WORD DQUOTE etc here
			perror("Add some error handling if this is wrong");
		cmd->argv[argc] = get_token_value(run);
		run = run->next;
		++argc;
		ret = parse_redirect(ret, &run);
	}
	cmd->argv[argc] = NULL;
	return (ret);
}

t_cmd	*parse_pipe(t_dlist **token)
{
	t_dlist		*run;
	t_cmd		*cmd;

	run = *token;
	cmd = parse_execution(&run);
	if (get_token_type(run) == TOKEN_PIPE)
	{
		run = run->next;
		cmd = parse_pipe(&run);
	}
	return (cmd);
}

t_cmd	*parse_command(t_dlist **token)
{
	t_dlist		*run;
	t_cmd		*cmd;

	run = *token;
	cmd = parse_pipe(&run);
	if (get_token_type(run) != TOKEN_EOF)
		perror("Did not finish parsing error");
	nullterminate(token);
	return (cmd);
}
