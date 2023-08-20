#ifndef PARSER_H
# define PARSER_H

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char	*cmd;
	char	**args;
	t_cmd	*next;
};

#endif
