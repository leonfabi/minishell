#include "libft.h"
#include "defines.h"

int	print(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

int	ft_echo(t_execcmd *cmd)
{
	t_bool	nl_flag;
	int		i;
	int		arr_len;

	nl_flag = TRUE;
	i = 0;
	arr_len = ft_arrlen((const char **)cmd->argv);
	if (NULL == cmd->argv[1])
		return (print(STDOUT_FILENO, "\n"), TRUE);
	if (ft_strncmp(cmd->argv[1], "-n", 3) == 0)
	{
		nl_flag = FALSE;
		++i;
	}
	while (++i < arr_len - 1)
		ft_fprintf(1, "%s ", cmd->argv[i]);
	if (cmd->argv[i] != NULL)
		ft_fprintf(1,"%s", cmd->argv[i]);
	if (nl_flag == TRUE)
		ft_fprintf(1, "\n");
	return (EXIT_SUCCESS);
}
