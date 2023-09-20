#ifndef UTILS_H
# define UTILS_H

# include "defines.h"

void	clean_ast(t_cmd *cmd);

void	msh_cleanup(t_main *sh);

t_cmd	**get_ast_root(void);

void	set_ast_root(t_cmd *root);

t_dlist	**get_lexer_root(void);

void	set_lexer_root(t_dlist *root);

void	general_error(char *s1, char *s2, char *s3);

#endif
