#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "defines.h"

void	executor(t_cmd *ast);
void	exec_ast(t_cmd *ast, t_context *ctx);
void	executor_main(t_cmd *ast);
void	execute_command(t_execcmd *exec, t_context *ctx);
t_bool	execute_builtin(t_execcmd *exec, t_context *ctx);

#endif
