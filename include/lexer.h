/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:25:38 by fkrug             #+#    #+#             */
/*   Updated: 2023/08/14 09:15:06 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_dlist t_dlist;

typedef enum e_type
{
	TOKEN_KEYWORD,
	TOKEN_FLAG,
	TOKEN_ARGUMENT,
	TOKEN_PIPE,
	TOKEN_LESS,
	TOKEN_GREATER,
	TOKEN_DLESS,
	TOKEN_DGREATER,
	TOKEN_EOF
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

#endif