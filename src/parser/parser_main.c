#include "minishell.h"

// FIX: On error checking we have to try to get a clean exit.
static t_cmd	*parse_redirect(t_cmd *cmd, t_dlist **tok, char **env)
{
	while (check_redirect(get_token_type(*tok)) == TRUE)
	{
		if (check_arguments(get_token_type((*tok)->next)) == FALSE)
			perror("missing file");
		cmd = select_redirect(cmd, *tok, env);
		*tok = (*tok)->next->next;
		if (NULL == *tok)
			perror("add something about EOF");
	}
	return (cmd);
}

static t_cmd	*parse_execution(t_dlist **tok, char **env)
{
	int			argc;
	t_execcmd	*cmd;
	t_cmd		*ret;

	ret = execcmd();
	cmd = (t_execcmd *)ret;
	ret = parse_redirect(ret, tok, env);
	argc = 0;
	while (check_metachars(get_token_type(*tok)) == FALSE)
	{
		if (get_token_type(*tok) == TOKEN_EOF)
			break ;
		if (check_arguments(get_token_type(*tok)) == FALSE)
			perror("Add some error handling if this is wrong");
		cmd->argv[argc] = expand_token(get_token(*tok), env);
		*tok = (*tok)->next;
		++argc;
		if (argc >= MAXARGS)
			perror("too many input arguments for the command");
		ret = parse_redirect(ret, tok, env);
	}
	cmd->argv[argc] = NULL;
	return (ret);
}

static t_cmd	*parse_pipe(t_dlist **tok, char **env)
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
