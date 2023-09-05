#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

void	setup(void)
{
	cr_redirect_stdout();
}

TestSuite(basic, .init = setup);

Test(basic, empty)
{
}
