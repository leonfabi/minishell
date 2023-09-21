#include "defines.h"

t_cmd	**get_ast_root(void)
{
	static t_cmd	*root;

	return (&root);
}

void	set_ast_root(t_cmd *root)
{
	t_cmd	**ast;

	ast = get_ast_root();
	*ast = root;
}

t_dlist	**get_lexer_root(void)
{
	static t_dlist	*root;

	return (&root);
}

void	set_lexer_root(t_dlist *root)
{
	t_dlist	**ast;

	ast = get_lexer_root();
	*ast = root;
}
