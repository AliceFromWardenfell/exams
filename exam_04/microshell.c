#include "microshell.h"

int	initialization(t_main *m, int argc, char ** argv, char **env)
{
	m->info.argc = argc;
	m->info.argv = argv;
	m->info.env = env;
	m->info.num_of_cmds = 1;
	m->cmd = NULL;
	return (OK);
}

int	wait_loop(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->pid != -1)
			if (waitpid(cmd->pid, NULL, 0) == -1)
			{
				printf("%d ", cmd->pid);
				return (print_error("waitpid"));
			}
		cmd = cmd->next;
	}
	return (OK);
}

int	main(int argc, char **argv, char **env)
{
	t_main m;

	initialization(&m, argc, argv, env);
	if (parser(&m))
		return (ERROR);
	if (executor(&m))
		return (ERROR);
	if (wait_loop(m.cmd))
		return (ERROR);
	return (OK);
}
