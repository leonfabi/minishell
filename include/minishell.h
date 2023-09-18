#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"
# include "expander.h"
# include "environment.h"
# include "signals.h"
# include "lexer.h"
# include "builtins.h"
# include "parser.h"
# include "executor.h"
# include "utils.h"

void	adv_free(char **to_free);
pid_t	adv_fork(void);

#endif
