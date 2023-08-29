#include "minishell.h"

// t_cmd	*parsepipe(t_cmd *cmd, t_dlist *head)
// {
// 	t_pipecmd	*pipe;
// 	t_pipecmd	*tmp;

// 	pipe = NULL;
// 	tmp =NULL;
// 	while(((t_token *)head->content)->type != TOKEN_EOF)
// 	{
// 		if (((t_token *)head->content)->type == TOKEN_PIPE)
// 		{
// 			pipe = (t_pipecmd *)malloc(sizeof(t_pipecmd));
// 			// if (pipe == NULL) Error handling
// 			pipe->type = PIPE;
// 			pipe->left = NULL;
// 			pipe->right = NULL;
// 			if (cmd == NULL)
// 				cmd = (t_cmd *)pipe;
// 			else
// 			{
// 				tmp = (t_pipecmd *)cmd;
// 				while (tmp->right != NULL)
// 					tmp = (t_pipecmd *)tmp->right;
// 				tmp->right = (t_cmd *)pipe;
// 			}
// 		}
// 		head = head->next;
// 	}
// 	return (cmd);
// }

t_cmd	*parsepipe(t_cmd *cmd, t_dlist *head)
{
	t_pipecmd	*pipe;
	t_pipecmd	*tmp;

	pipe = NULL;
	tmp =NULL;
	pipe = (t_pipecmd *)malloc(sizeof(t_pipecmd));
	// if (pipe == NULL) Error handling
	pipe->type = PIPE;
	pipe->left = NULL;
	pipe->right = NULL;
	if (cmd == NULL)
		cmd = (t_cmd *)pipe;
	else
	{
		tmp = (t_pipecmd *)cmd;
		while (tmp->right != NULL)
			tmp = (t_pipecmd *)tmp->right;
		tmp->right = (t_cmd *)pipe;
	}
	return (cmd);
}

t_cmd	*parseexecmd(t_cmd *cmd, t_dlist *head)
{
	t_execcmd	*execmd;
	t_command	*tmp;

	tmp = (t_command *)cmd;
	execmd = NULL;
	execmd = (t_execcmd *)malloc(sizeof(t_execcmd));
	// Error handling
	execmd->type = EXECUTE;
	execmd->argv = NULL;
	execmd->bin = NULL;
	execmd->envp = NULL;
	if (tmp->exec == NULL)
		tmp->exec = (t_cmd*)execmd;
	// else
	// {

	// }
	return (cmd);
}

t_cmd	*parseredir(t_cmd *cmd, t_dlist *head)
{
	t_redircmd	*redir;
	t_command	*tmp;

	tmp = (t_command *)cmd;
	// Check next token
	redir = NULL;
	redir = (t_redircmd *)malloc(sizeof(t_redircmd));
	// Error handling
	redir->type = EXECUTE;
	redir->cmd = NULL;
	redir->next = NULL;
	redir->file = NULL;
	redir->mode = 0;
	redir->fd = 0;
	if (tmp->red == NULL)
		tmp->red = (t_cmd*)redir;
	// else
	// {

	// }
	return (cmd);
}

t_cmd	*parsecommand(t_cmd *cmd, t_dlist *head)
{
	while (((t_token *)head->content)->type != TOKEN_EOF && \
	((t_token *)head->content)->type != TOKEN_PIPE)
	{
		if (((t_token *)head->content)->type == TOKEN_WORD || \
		((t_token *)head->content)->type == TOKEN_QUOTE || \
		((t_token *)head->content)->type == TOKEN_DQUOTE)
			cmd = parseexecmd(cmd, head); // Add Execcmd node
		else if (((t_token *)head->content)->type == TOKEN_DGREATER || \
		((t_token *)head->content)->type == TOKEN_DLESS || \
		((t_token *)head->content)->type == TOKEN_GREATER || \
		((t_token *)head->content)->type == TOKEN_LESS)
			cmd = parseredir(cmd, head);
		head = head->next;
	}
}

t_cmd	*ft_parser(t_lexer *lexer)
{
	t_dlist	*head;
	t_cmd	*tree_head;

	tree_head = NULL;
	head = lexer->token_list;
	while(((t_token *)head->content)->type != TOKEN_EOF)
	{
		if (((t_token *)head->content)->type == TOKEN_PIPE)
			tree_head = parsepipe(tree_head, head);
		else
			tree_head = parsecommand(tree_head, head);
		head = head->next;
	}
	return (tree_head);
}
