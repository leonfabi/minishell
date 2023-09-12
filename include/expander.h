#ifndef EXPANDER_H
# define EXPANDER_H

# include "defines.h"

/* `<SUMMARY>`:
 * Main entry point for expanding tokens when having a `$`
 * and not being a QUOTE token.
 * `<PARAM>`:
 * `tok`: token to get expanded;
 * `env`: array of strings of the environment variables;
 * `<RETURN>`:
 * Returns a freeable string with the expanded token. */
char	*expand_token(t_token *tok, char **env);

/* `<SUMMARY>`:
 * Creates a linked list of keys to get expanded..
 * `<PARAM>`:
 * `input`: String value from a token;
 * `<RETURN>`:
 * Returns a pointer to the start of a linked list containing the keys. */
t_list	*create_keylist(char *input);

/* `<SUMMARY>`:
 * Function to expand special strings like $$, $? etc..
 * `<PARAM>`:
 * `input`: String value from a token;
 * `<RETURN>`:
 * Returns a freeable string with the expanded token. */
char	*expand_special(char *input);

#endif
