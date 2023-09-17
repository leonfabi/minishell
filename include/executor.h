#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "defines.h"

void	executor(t_cmd *ast);
void	executor_mk(t_cmd *ast, int fd);

#endif
