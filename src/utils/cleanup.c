#include "libft.h"
#include "defines.h"
#include "utils.h"

void	here_cleanup(void)
{
	clean_ast(*get_ast_root());
	ft_arrfree(*get_env_arr());
	ft_arrfree(*get_bin_path());
}

void	msh_cleanup(t_main *sh)
{
	clean_ast(*get_ast_root());
	close(sh->stdin);
	close(sh->stdout);
	close(sh->stderr);
	ft_arrfree(sh->bin_path);
	ft_arrfree(sh->env);
}
