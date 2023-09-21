#include "minishell.h"
#include "libft.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

extern char	**environ;

////////////////////////////////////////////////////////////////////////////////
//////////////                    echo                        //////////////////
////////////////////////////////////////////////////////////////////////////////

void	redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

TestSuite(echo, .init = redirect_all_std);

Test(echo, echo_no_nl)
{
	t_execcmd	cmd;

	cmd = (t_execcmd){
		.argv = {
			"echo",
			"-n",
			"first",
			"second",
			"third",
			"fourth"
		}
	};
	ft_echo(&cmd);
	fflush(stdout);
	cr_assert_stdout_eq_str("first second third fourth");
}

Test(echo, no_argv)
{
	t_execcmd	cmd;

	cmd = (t_execcmd){
		.argv = {"echo"}
	};
	ft_echo(&cmd);
	fflush(stdout);
	cr_assert_stdout_eq_str("\n");
}

Test(echo, no_argv_no_nl)
{
	t_execcmd	cmd;

	cmd = (t_execcmd){
		.argv = {
			"echo",
			"-n"
		}
	};
	ft_echo(&cmd);
	fflush(stdout);
	cr_assert_stdout_eq_str("");
}

Test(echo, single_argv)
{
	t_execcmd	cmd;

	cmd = (t_execcmd){
		.argv = {
			"echo",
			"testing"
		}
	};
	ft_echo(&cmd);
	fflush(stdout);
	cr_assert_stdout_eq_str("testing\n");
}

Test(echo, single_argv_no_nl)
{
	t_execcmd	cmd;

	cmd = (t_execcmd){
		.argv = {
			"echo",
			"-n",
			"-n"
		}
	};
	ft_echo(&cmd);
	fflush(stdout);
	cr_assert_stdout_eq_str("-n");
}

Test(echo, double_argv)
{
	t_execcmd	cmd;

	cmd = (t_execcmd){
		.argv = {
			"echo",
			"testing",
			"yes"
		}
	};
	ft_echo(&cmd);
	fflush(stdout);
	cr_assert_stdout_eq_str("testing yes\n");
}

////////////////////////////////////////////////////////////////////////////////
//////////////                   export                       //////////////////
////////////////////////////////////////////////////////////////////////////////


TestSuite(export);

// base construction
// Test(export, export_single)
// {
// 	t_execcmd	cmd;
// 	char		*result;
// 	t_main		sh;
// 
// 	cmd = (t_execcmd){};
// 	sh.env = ft_arrdup((const char **)environ);
// 	cmd.sh = &sh;
// 	cmd.argv[0] = "export";
// 	cmd.argv[1] = "TEST=42";
// 	cmd.argv[2] = NULL;
// 
// 	ft_export(&cmd);
// 	result = get_env(sh.env, "TEST");
// 	cr_assert(eq(str, result, "42"));
// 	ft_arrfree(sh.env);
// }

Test(export, export_single)
{
	t_execcmd	cmd;
	char		*result;
	t_main		sh;

	cmd = (t_execcmd){};
	sh.env = ft_arrdup((const char **)environ);
	cmd.sh = &sh;
	cmd.argv[0] = "export";
	cmd.argv[1] = "TEST=42";
	cmd.argv[2] = NULL;

	ft_export(&cmd);
	result = get_env(sh.env, "TEST");
	cr_assert(eq(str, result, "42"));
	ft_arrfree(sh.env);
	free(result);
}


// #include <errno.h>

// int	main(void)
// {
// 	t_execcmd	cmd;
// 	t_execcmd	cmd1;
// 	char		**env;
// 	t_main		sh;
// 
// 
// 	env = ft_calloc(5, sizeof(*env));
// 	env[0] = ft_strdup("_USERNAME=none");
// 	env[1] = ft_strdup("USER=makurz");
// 	env[2] = ft_strdup("TEST=42Hello");
// 	env[3] = ft_strdup("VERRUCKT=");
// 	init_shell(&sh, env);
// 	printf("%s\n", env[0]);
// 	printf("%s\n", env[1]);
// 	cmd = (t_execcmd){};
// 	cmd.argv[0] = ft_strdup("export");
// 	cmd.argv[1] = ft_strdup("TEST42_=42Hello");
// 	cmd.argv[2] = ft_strdup("42TEST=42Hello");
// 	cmd.argv[3] = ft_strdup("USER=fkrug");
// 	cmd.argv[4] = ft_strdup("#WRONG");
// 	cmd.argv[5] = ft_strdup("NOTHING");
// 	printf("\n");
// 	ft_arrprint((const char **)cmd.argv);
// 	// cmd.argv[3] = ft_strdup("USER=fkrug");
// 	// cmd.argv[4] = ft_strdup("VERRUCKT");
// 	cmd.sh = &sh;
// 	// cmd.argv[2] = "42TEST=Hallo";
// 	printf("\n");
// 	ft_export(&cmd);
// 	int	i = -1;
// 	printf("\n");
// 	ft_arrprint((const char **)cmd.sh->env);
// 	cmd1 = (t_execcmd){};
// 	cmd1.argv[0] = ft_strdup("unset");
// 	cmd1.argv[1] = ft_strdup("TEST42_");
// 	cmd1.sh = &sh;
// 	ft_unset(&cmd1);
// 	printf("\n\n\n");
// 	ft_arrprint((const char **)cmd.sh->env);
// 	while (cmd.argv[++i] != NULL)
// 		free(cmd.argv[i]);
// 	ft_arrfree(env);
// 	ft_arrfree(sh.env);
// 	printf("\nExit Status: %d\n", *get_exit_status());
// 	return (0);
// }
