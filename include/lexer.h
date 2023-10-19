/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:17 by fkrug             #+#    #+#             */
/*   Updated: 2023/10/19 11:48:18 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/* `<SUMMARY>`:
 * Function to allocate memory for a new node in the double
 * linked list and also to input the content into the struct.
 * `<PARAM>`:
 * `content`: pointer to a universal void pointer for the content;
 * `<RETURN>`:
 * Freeable node for the double linked list or NULL if failed. */
t_dlist		*ft_dlstnew(void *content);

/* `<SUMMARY>`:
 * Function for cleaning a pipe command. It recursively calls the
 * `clean_ast` command of the left and right branch of the pipe node.
 * Subsequently frees the pipe node.
 * `<PARAM>`:
 * `lst`: pointer to the current head of the double linked list;
 * `add`: node to be added to the end of the double linked list;
 * `<RETURN>`:
 * `TRUE` on success `FALSE` on failure. */
t_bool		ft_dlstadd_back(t_dlist **lst, t_dlist *add);

/* `<SUMMARY>`:
 * Helper function to check if the current section that is being processed
 * of the string is still part of the word token.
 * `<PARAM>`:
 * `c`: character to be checked;
 * `<RETURN>`:
 * `TRUE` on success `FALSE` on failure. */
t_bool		ft_is_section(char c);

/* `<SUMMARY>`:
 * Helper function to skip any kind of whitespaces as defined
 * in the libc `isspace` function.
 * `<PARAM>`:
 * `lexer`: main struct of the lexer;
 * `<RETURN>`:
 * NOTHING. */
void		ft_skip_whitespace(t_lexer *lexer);

/* `<SUMMARY>`:
 * Error message function if something went wrong during lexing.
 * `<PARAM>`:
 * `lexer`: main struct of the lexer;
 * `str`: error message that should be printed out;
 * `<RETURN>`:
 * NOTHING. */
void		error_msg(t_lexer *lexer, char *str);

/* `<SUMMARY>`:
 * Cleanup function to free the memory of the double linked list
 * in the occurrence of an error or after the parser is finished.
 * `<PARAM>`:
 * `lst`: pointer to the current head of the double linked list;
 * `*del`: function pointer to the given function (e.g. &free);
 * `<RETURN>`:
 * NOTHING. */
void		ft_dlstclear(t_dlist **lst, void (*del)(void *));

t_lexer		ft_lexer(char *str);
t_token		*ft_create_token(t_type type, t_lexer *lexer);
t_bool		ft_find_token(t_lexer *lexer);
t_bool		ft_make_append_token(t_lexer *lexer, t_type type);

#endif
