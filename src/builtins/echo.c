#include "minishell.h"

int	print(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

int	echo(char **arg)
{
	t_bool	new_line;
	int		count;
	t_bool	print_check;

	count = 0;
	print_check = FALSE;
	new_line = TRUE;
	if (arg[0] == NULL)
		return (print(STDOUT_FILENO, "\n"), TRUE);
	if (ft_strcmp(arg[0], "-n") == 0)
	{
		new_line = FALSE;
		count++;
	}
	while (arg[count] != NULL)
	{
		if (print_check == TRUE)
			print(STDOUT_FILENO, " ");
		print(STDOUT_FILENO, arg[count]);
		print_check = TRUE;
		count++;
	}
	if (new_line == TRUE)
		print(STDOUT_FILENO, "\n");
	return (TRUE);
}
