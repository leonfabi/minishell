#include "minishell.h"

/* `<SUMMARY>`:
 * Main function for parsing a redirect token.
 * `<PARAM>`:
 * `cmd`: command node of a redirection node;
 * `tok`: double linked list of the tokens;
 * `sh`: Main struct holding all the attributes of the shell;
 * `<RETURN>`:
 * Returns a initialized redirect node. */
static t_cmd	*parse_redirect(t_cmd *cmd, t_dlist **tok, t_main *sh)
{
	while (check_redirect(get_token_type(*tok)) == TRUE)
	{
		// FIX: add proper error handling if there is a missing file
		if (check_arguments(get_token_type((*tok)->next)) == FALSE)
		{
			general_error(NO_FILE, NULL, NULL);
			set_exit_status(2);
			(*tok) = (*tok)->next;
			return (NULL);
		}
		cmd = select_redirect(cmd, tok, sh->env);
	}
	return (cmd);
}

char	*connect_tokens(t_dlist **list, char **env)
{
	char	*expand;
	t_token	*tok;

	expand = expand_token(get_token(*list), env);
	tok = get_token(*list);
	if (check_tok_connection(tok) == FALSE)
	{
		*list = (*list)->next;
		return (expand);
	}
	*list = (*list)->next;
	while (get_token_type(*list) & (TOKEN_WORD | TOKEN_DQUOTE | TOKEN_QUOTE))
	{
		tok = get_token(*list);
		expand = ft_strjoinfree(expand, expand_token(tok, env), 'B');
		if (check_tok_connection(tok) == FALSE)
		{
			*list = (*list)->next;
			return (expand);
		}
		*list = (*list)->next;
	}
	return (expand);
}

/* `<SUMMARY>`:
 * Main function for parsing a execution token.
 * `<PARAM>`:
 * `tok`: double linked list of the tokens;
 * `sh`: Main struct holding all the attributes of the shell;
 * `<RETURN>`:
 * Returns a initialized execution node. */
static t_cmd	*parse_execution(t_dlist **tok, t_main *sh)
{
	int			argc;
	t_execcmd	*cmd;
	t_cmd		*ret;

	ret = execcmd(sh);
	cmd = (t_execcmd *)ret;
	ret = parse_redirect(ret, tok, sh);
	argc = 0;
	while (check_metachars(get_token_type(*tok)) == FALSE)
	{
		if (get_token_type(*tok) == TOKEN_EOF)
			break ;
		if (check_arguments(get_token_type(*tok)) == FALSE)
			perror("Add some error handling if this is wrong");
		cmd->argv[argc] = connect_tokens(tok, sh->env);
		++argc;
		if (argc >= MAXARGS)
		{
			general_error("exec", ERR_ARG, NULL);
			return (NULL);
		}
		ret = parse_redirect(ret, tok, sh);
	}
	cmd->argv[argc] = NULL;
	return (ret);
}

/* `<SUMMARY>`:
 * Main function for parsing a pipe token.
 * `<PARAM>`:
 * `tok`: double linked list of the tokens;
 * `sh`: Main struct holding all the attributes of the shell;
 * `<RETURN>`:
 * Returns a initialized pipe node. */
static t_cmd	*parse_pipe(t_dlist **tok, t_main *sh)
{
	t_cmd		*cmd;

	cmd = parse_execution(tok, sh);
	if (get_token_type(*tok) == TOKEN_PIPE)
	{
		// FIX: check for NULL dereference
		*tok = (*tok)->next;
		cmd = pipecmd(cmd, parse_pipe(tok, sh));
	}
	return (cmd);
}

t_cmd	*parse_command(t_dlist **tok, t_main *sh)
{
	t_cmd		*cmd;

	if (sh->lexer.error_code == -1)
	{
		return (NULL);
	}
	cmd = parse_pipe(tok, sh);
	if (get_token_type(*tok) != TOKEN_EOF)
	{
		general_error("parsing", ERR_PARS, NULL);
	}
	ft_dlstclear(get_lexer_root(), &free);
	set_lexer_root(NULL);
	set_ast_root(cmd);
	return (cmd);
}
