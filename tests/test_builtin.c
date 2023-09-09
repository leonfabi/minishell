#include "minishell.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

extern char	**environ;

// void	redirect_all_std(void)
// {
// 	cr_redirect_stdout();
// 	cr_redirect_stderr();
// }
// 
// TestSuite(builtins, .init = redirect_all_std);
// 
// ////////////////////////////////////////////////////////////////////////////////
// //////////////                    echo                        //////////////////
// ////////////////////////////////////////////////////////////////////////////////
// 
// Test(builtins, echo_no_nl)
// {
// 	t_execcmd	cmd;
// 
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = "echo";
// 	cmd.argv[1] = "-n";
// 	cmd.argv[2] = "first";
// 	cmd.argv[3] = "second";
// 	cmd.argv[4] = "third";
// 	cmd.argv[5] = "fourth";
// 	ft_echo(&cmd);
// 	fflush(stdout);
// 	cr_assert_stdout_eq_str("first second third fourth");
// }
// 
// Test(builtins, no_argv)
// {
// 	t_execcmd	cmd;
// 
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = "echo";
// 	ft_echo(&cmd);
// 	fflush(stdout);
// 	cr_assert_stdout_eq_str("\n");
// }
// 
// Test(builtins, no_argv_no_nl)
// {
// 	t_execcmd	cmd;
// 
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = "echo";
// 	cmd.argv[1] = "-n";
// 	ft_echo(&cmd);
// 	fflush(stdout);
// 	cr_assert_stdout_eq_str("");
// }
// 
// Test(builtins, single_argv)
// {
// 	t_execcmd	cmd;
// 
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = "echo";
// 	cmd.argv[1] = "testing";
// 	ft_echo(&cmd);
// 	fflush(stdout);
// 	cr_assert_stdout_eq_str("testing\n");
// }
// 
// Test(builtins, single_argv_no_nl)
// {
// 	t_execcmd	cmd;
// 
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = "echo";
// 	cmd.argv[1] = "-n";
// 	cmd.argv[2] = "-n";
// 	ft_echo(&cmd);
// 	fflush(stdout);
// 	cr_assert_stdout_eq_str("-n");
// }
// 
// Test(builtins, double_argv)
// {
// 	t_execcmd	cmd;
// 
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = "echo";
// 	cmd.argv[1] = "testing";
// 	cmd.argv[2] = "yes";
// 	ft_echo(&cmd);
// 	fflush(stdout);
// 	cr_assert_stdout_eq_str("testing yes\n");
// }

////////////////////////////////////////////////////////////////////////////////
//////////////                   export                       //////////////////
////////////////////////////////////////////////////////////////////////////////


// TestSuite(export);
// 
// Test(export, export_single)
// {
// 	t_execcmd	cmd;
// 	char		**env;
// 
// 	env = NULL;
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = "export";
// 	cmd.argv[1] = "TEST=42";
// 	// cmd.argv[2] = "42TEST=Hallo";
// 
// 	ft_export(&cmd, env);
// 	printf("%s\n", env[0]);
// }
//

#include <errno.h>

int	main(void)
{
	t_execcmd	cmd;
	char		**env;
	t_main		sh;


	env = ft_calloc(3, sizeof(*env));
	env[0] = ft_strdup("USERNAME=none");
	env[1] = ft_strdup("USER=makurz");
	init_shell(&sh, env);
	printf("%s\n", env[0]);
	printf("%s\n", env[1]);
	cmd = (t_execcmd){};
	cmd.argv[0] = ft_strdup("export");
	cmd.argv[1] = ft_strdup("TEST42_=42Hello");
	cmd.argv[2] = ft_strdup("42TEST=42Hello");
	cmd.argv[5] = ft_strdup("#WRONG");
	cmd.argv[3] = ft_strdup("USER=fkrug");
	cmd.argv[4] = ft_strdup("VERRUCKT");
	cmd.sh = &sh;
	// cmd.argv[2] = "42TEST=Hallo";
	printf("\n");
	ft_export(&cmd);
	int	i = -1;
	ft_arrprint((const char **)cmd.sh->env);
	i = -1;
	while (cmd.argv[++i] != NULL)
		free(cmd.argv[i]);
	ft_arrfree(env);
	return (0);
}
