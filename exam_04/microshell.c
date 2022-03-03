#include "microshell.h"

int	initialization(t_main *m, int argc, char ** argv, char **env)
{
	m->info.argc = argc;
	m->info.argv = argv;
	m->info.env = env;
	m->cmd = NULL;
	m->backup_fd_in = dup(0);
	if (m->backup_fd_in == -1)
		fatal_error();
	m->backup_fd_out = dup(1);
	if (m->backup_fd_out == -1)
		fatal_error();
	m->pipe[0] = -1;
	m->pipe[1] = -1;
	return (OK);
}

int	wait_loop(t_cmd *cmd)
{
	while (cmd)
	{
		// printf("%d\n", cmd->pid);
		if (cmd->pid != -1 && cmd->pid != 0)
			if (waitpid(cmd->pid, NULL, 0) == -1)
				fatal_error();
		cmd = cmd->next;
	}
	return (OK);
}

int	list_free(t_main *m)
{
	t_cmd *cmd;
	t_cmd *tmp;
	int		i;

	cmd = m->cmd;
	while (cmd)
	{
		i = -1;
		while (++i < cmd->argc)
			free(cmd->args[i]);
		free(cmd->args);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
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
	fd_restore(&m);
	if (close(m.backup_fd_in) == -1)
		fatal_error();
	if (close(m.backup_fd_out) == -1)
		fatal_error();
	list_free(&m);
	return (OK);
}
