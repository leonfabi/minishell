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

int		get_token_length(t_dlist *token)
{
	t_token		*tok;

	tok = (t_token *)token->content;
	return (tok->value_length);
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

t_cmd	*select_redirect(t_cmd *subcmd, t_dlist *tok_list)
{
	t_token		*redir;
	t_token		*file;

	redir = get_token(tok_list);
	file = get_token(tok_list->next);
	if (redir->type == TOKEN_LESS)
		return (redircmd(subcmd, file, O_RDONLY, 0));
	if (redir->type == TOKEN_GREATER)
		return (redircmd(subcmd, file, O_WRONLY | O_RDONLY, 1));
	if (redir->type == TOKEN_DGREATER)
		return (redircmd(subcmd, file, O_WRONLY | O_CREAT, 1));
	// here we have to find something for the heredoc
	return (NULL);
}

t_cmd	*parse_redirect(t_cmd *cmd, t_dlist **tok)
{
	while (check_redirect(get_token_type(*tok)) == TRUE)
	{
		if (check_arguments(get_token_type((*tok)->next)) == FALSE)
			perror("missing file"); // get exit here
		cmd = select_redirect(cmd, *tok);
		*tok = (*tok)->next->next;
		if (NULL == *tok)
			perror("add something about EOF");
	}
	return (cmd);
}

t_cmd	*parse_execution(t_dlist **tok, char **env)
{
	int			argc;
	t_execcmd	*cmd;
	t_cmd		*ret;

	ret = execcmd();
	cmd = (t_execcmd *)ret;
	ret = parse_redirect(ret, tok);
	argc = 0;
	while (check_metachars(get_token_type(*tok)) == FALSE)
	{
		if (get_token_type(*tok) == TOKEN_EOF)
			break ;
		if (check_arguments(get_token_type(*tok)) == FALSE)
			perror("Add some error handling if this is wrong");
		cmd->argv[argc] = expand_token(get_token(*tok), env);
		// cmd->argv[argc] = get_token_value(*tok);
		*tok = (*tok)->next;
		++argc;
		if (argc >= 15)
			perror("too many input arguments for the command");
		ret = parse_redirect(ret, tok);
	}
	cmd->argv[argc] = NULL;
	return (ret);
}

t_cmd	*parse_pipe(t_dlist **tok, char **env)
{
	t_cmd		*cmd;

	cmd = parse_execution(tok, env);
	if (get_token_type(*tok) == TOKEN_PIPE)
	{
		*tok = (*tok)->next;
		cmd = pipecmd(cmd, parse_pipe(tok, env));
	}
	return (cmd);
}

t_cmd	*parse_command(t_dlist **tok, char **env)
{
	t_dlist		*keep;
	t_cmd		*cmd;

	keep = *tok;
	cmd = parse_pipe(tok, env);
	if (get_token_type(*tok) != TOKEN_EOF)
		perror("Did not finish parsing error");
	nulterminate(&keep);
	return (cmd);
}
