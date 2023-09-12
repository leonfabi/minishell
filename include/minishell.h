#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <errno.h>
# include "defines.h"
# include "environment.h"
# include "signal_handler.h"
# include "lexer.h"
# include "builtins.h"
# include "parser.h"
# include "executor.h"

void	adv_free(char **to_free);

#endif
