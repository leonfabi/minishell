#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

void	ft_print_token_list(t_lexer *lexer);

char* types[] = {
	"TOKEN_WORD",
	"TOKEN_FLAG",
	"TOKEN_PIPE",
	"TOKEN_LESS",
	"TOKEN_GREATER",
	"TOKEN_DLESS",
	"TOKEN_DGREATER",
	"TOKEN_EOF",
	"TOKEN_QUOTE",
	"TOKEN_DQUOTE",
	"TOKEN_NEWLINE"
};

void	n_token(t_lexer *lexer, int nb)
{
	int		i;

	i = -1;
	while (++i < nb - 1)
		lexer->token_list = lexer->token_list->next;
}

void	get_values(t_lexer lexer, t_type *type, int *len, char value[20])
{
	*type = ((t_token *)lexer.token_list->content)->type;
	*len = ((t_token *)lexer.token_list->content)->value_length;
	strncpy(value, ((t_token *)lexer.token_list->content)->value, *len);
}

// Test for single char tokens
Test(single_char, greater)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer(">");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, ">"));
	cr_assert(eq(str, "TOKEN_GREATER", types[type]));
	cr_assert(eq(int, 1, len));
}

Test(random, random)
{

	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("echo \"Hello World\" | < < ls -a >");
	n_token(&lexer, 4);
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "<"));
	cr_assert(eq(str, "TOKEN_LESS", types[type]));
	cr_assert(eq(int, 1, len));
}

Test(single_char, greater_as_8)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("echo \"Hello World\" | < < ls -a >");
	n_token(&lexer, 8);
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, ">"));
	cr_assert(eq(str, "TOKEN_GREATER", types[type]));
	cr_assert(eq(int, 1, len));
}

Test(single_char, less)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("<");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "<"));
	cr_assert(eq(str, "TOKEN_LESS", types[type]));
	cr_assert(eq(int, 1, len));
}

Test(single_char, less_as_fourth)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("word | > <");
	n_token(&lexer, 4);
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "<"));
	cr_assert(eq(str, "TOKEN_LESS", types[type]));
	cr_assert(eq(int, 1, len));
}

Test(single_char, pipe)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("|");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "|"));
	cr_assert(eq(str, "TOKEN_PIPE", types[type]));
	cr_assert(eq(int, 1, len));
}

Test(single_char, pipe_as_second)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("this |");
	n_token(&lexer, 2);
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "|"));
	cr_assert(eq(str, "TOKEN_PIPE", types[type]));
	cr_assert(eq(int, 1, len));
}

Test(single_char, eof)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("asdfasd");
	lexer.token_list = lexer.token_list->next;
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, ""));
	cr_assert(eq(str, "TOKEN_EOF", types[type]));
	cr_assert(eq(int, 0, len));
}
// Test for double char tokens

Test(double_char, dgreater)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer(">>");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, ">>"));
	cr_assert(eq(str, "TOKEN_DGREATER", types[type]));
	cr_assert(eq(int, 2, len));
}

Test(double_char, dless)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("<<");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "<<"));
	cr_assert(eq(str, "TOKEN_DLESS", types[type]));
	cr_assert(eq(int, 2, len));
}

Test(double_char, dless_as_third)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("test -l <<");
	n_token(&lexer, 3);
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "<<"));
	cr_assert(eq(str, "TOKEN_DLESS", types[type]));
	cr_assert(eq(int, 2, len));
}

// Test for multiple char tokens
Test(multi_char, quote)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("'test'");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "test"));
	cr_assert(eq(str, "TOKEN_QUOTE", types[type]));
	cr_assert(eq(int, 4, len));
}

Test(multi_char, dquote)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("\"dquotes\"");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "dquotes"));
	cr_assert(eq(str, "TOKEN_DQUOTE", types[type]));
	cr_assert(eq(int, 7, len));
}

Test(multi_char, inner_quotes)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("\"'dquotes'\"");
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "'dquotes'"));
	cr_assert(eq(str, "TOKEN_DQUOTE", types[type]));
	cr_assert(eq(int, 9, len));
}

Test(multi_char, word)
{
	int			len;
	char		value[20];
	char		test[] = "hallo";
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer(test);
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "hallo"));
	cr_assert(eq(str, "TOKEN_WORD", types[type]));
	cr_assert(eq(int, 5, len));
}

Test(multi_char, dquote_second)
{
	int			len;
	char		value[20];
	t_lexer		lexer;
	t_type		type;

	lexer = ft_lexer("\"dquotes\" \"hello\" echo << |");
	n_token(&lexer, 2);
	get_values(lexer, &type, &len, value);
	cr_assert(eq(str, value, "hello"));
	cr_assert(eq(str, "TOKEN_DQUOTE", types[type]));
	cr_assert(eq(int, 5, len));
}

void	ft_print_token_list(t_lexer *lexer)
{
	int		len;
	int		count;
	t_type	type;

	len = 0;
	while(lexer->token_list != NULL)
	{
		count = 0;
		type = ((t_token *)lexer->token_list->content)->type;
		len = ((t_token *)lexer->token_list->content)->value_length;
		printf("TOKEN: %s\t", types[type]);
		while (len > count)
		{
			printf("%c", ((t_token *)lexer->token_list->content)->value[count]);
			count++;
		}
		printf("\n-----------------------\n");
		lexer->token_list = lexer->token_list->next;
	}
}
