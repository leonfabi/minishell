#ifndef LEXER_H
# define LEXER_H

# include "defines.h"

// UTILS
t_dlist		*ft_dlstnew(void *content);
t_bool		ft_dlstadd_back(t_dlist **lst, t_dlist *add);
t_bool		ft_is_section(char c);
void		ft_skip_whitespace(t_lexer *lexer);
void		error_msg(t_lexer *lexer, char *str);
void		ft_dlstclear(t_dlist **lst, void (*del)(void *));

t_lexer		ft_lexer(char *str);
t_token		*ft_create_token(t_type type, t_lexer *lexer);
t_bool		ft_find_token(t_lexer *lexer);
t_bool		ft_make_append_token(t_lexer *lexer, t_type type);

#endif
