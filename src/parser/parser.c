#include "minishell.h"

t_cmd	*parsepipe(t_cmd *cmd, t_dlist *head)
{
	t_pipecmd	*pipe;
	t_pipecmd	*tmp;

	pipe = NULL;
	tmp =NULL;
	while(((t_token *)head->content)->type != TOKEN_EOF)
	{
		if (((t_token *)head->content)->type == TOKEN_PIPE)
		{
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
					tmp = tmp->right;
				tmp->right = pipe;
			}
		}
		head = head->next;
	}
	return (cmd);
}

t_cmd	*ft_parser(t_lexer *lexer)
{
	t_dlist	*head;
	t_cmd	*tree_head;

	head = lexer->token_list;
	tree_head = NULL;
	while(((t_token *)head->content)->type != TOKEN_EOF)
	{
		// search for pipe
		tree_head = parsepipe(tree_head, head);
		// search for redirect
		head = head->next;
	}
}
