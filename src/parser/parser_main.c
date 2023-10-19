/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:46:22 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/19 11:46:23 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "parser.h"
#include "lexer.h"
#include "expander.h"
#include "utils.h"
#include "signals.h"

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
		if (check_arguments(get_token_type((*tok)->next)) == FALSE)
		{
			sh->pars_error = TRUE;
			(*tok) = (*tok)->next;
			return (cmd);
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
		if (check_arguments(get_token_type(*tok)) == FALSE)
			break ;
		cmd->argv[argc] = connect_tokens(tok, sh->env);
		++argc;
		if (argc >= MAXARGS)
		{
			general_error("exec", ERR_ARG, NULL);
			sh->pars_error = TRUE;
			return (ret);
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
	if (cmd->type == EXECUTE && ((t_execcmd *)cmd)->argv[0] == NULL)
	{
		sh->pars_error = TRUE;
	}
	if (sh->pars_error == TRUE)
	{
		return (cmd);
	}
	if (get_token_type(*tok) == TOKEN_PIPE)
	{
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
	if (sh->pars_error == TRUE)
	{
		parse_error(get_token_type(*tok));
		set_exit_status(2);
		clean_ast(cmd);
		cmd = NULL;
	}
	ft_dlstclear(get_lexer_root(), &free);
	set_lexer_root(NULL);
	set_ast_root(cmd);
	return (cmd);
}
