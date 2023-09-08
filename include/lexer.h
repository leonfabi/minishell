#ifndef LEXER_H
# define LEXER_H

# include "defines.h"
# include <string.h>
# include <stdio.h>

typedef struct s_dlist	t_dlist;

typedef enum e_type
{
	TOKEN_WORD,
	TOKEN_FLAG,
	TOKEN_PIPE,
	TOKEN_LESS,
	TOKEN_GREATER,
	TOKEN_DLESS,
	TOKEN_DGREATER,
	TOKEN_EOF,
	TOKEN_QUOTE,
	TOKEN_DQUOTE,
	TOKEN_NEWLINE
}	t_type;

typedef struct s_dlist
{
	void	*content;
	t_dlist	*next;
	t_dlist	*prev;
}	t_dlist;

typedef struct s_token
{
	t_type	type;
	char	*value;
	int		len;
}	t_token;

typedef struct s_lexer
{
	char	*start;
	char	*counter;
	t_dlist	*token_list;
	int		error_code;
}	t_lexer;

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
