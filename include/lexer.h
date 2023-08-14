/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:25:38 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/14 14:54:13 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_dlist	t_dlist;

typedef enum e_type
{
	TOKEN_KEYWORD,
	TOKEN_FLAG,
	TOKEN_PIPE,
	TOKEN_LESS,
	TOKEN_GREATER,
	TOKEN_DLESS,
	TOKEN_DGREATER,
	TOKEN_EOF,
	TOKEN_QUOTE,
	TOKEN_DQUOTE
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
	int		value_length;
}	t_token;

typedef struct s_lexer
{
	char	*start;
	char	*counter;
	t_dlist	*token_list;
}	t_lexer;

// UTILS
t_dlist	*ft_dlstnew(void *content);
int		ft_dlstadd_back(t_dlist **lst, t_dlist *new);
int	ft_is_section(char c);
void	ft_skip_whitespace(t_lexer *lexer);

t_token	*ft_lexer(char *str);
t_token	*ft_create_token(t_type type, t_lexer *lexer);

#endif