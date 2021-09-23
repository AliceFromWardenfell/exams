#include "microshell.h"

int	builtin_check(t_cmd *cmd)
{
	if (!strcmp(cmd->args[0], "cd"))
		return (TRUE);
	return (FALSE);
}

int	cd_b(t_cmd *cmd)
{
	int		argc;

	argc = 0;
	while (cmd->args[argc])
		argc++;
	if (argc != 2)
		return (print_error("cd: bad arguments"));
	if (chdir(cmd->args[1]) == -1)
	{
		printf("error: cd: cannot change directory to %s\n", cmd->args[1]);
		return (2);
	}
	// printf("dir has been changed to %s\n", cmd->args[1]);
	return (OK);
}

int	execute(t_main *m, t_cmd *cmd, char **env)
{	
	cmd->pid = fork();
	if (!cmd->pid)
	{
		if (m->pipe[0] != -1)
			close(m->pipe[0]);
		if (m->pipe[1] != -1)
			close(m->pipe[1]);
		if (execve(cmd->args[0], cmd->args, env) == -1)
		{
			printf("error: cannot execute %s\n", cmd->args[0]);
		}
		exit(OK);
	}
	return (OK);
}

int	do_pipe(t_main *m, t_cmd *cmd, int *fd_in, int *fd_out)
{
	if (m->pipe[0] == -1)
		*fd_in = 0;
	dup2(*fd_in, 0);
	if (m->pipe[0] != -1)
	{
		close(m->pipe[0]);
		m->pipe[0] = -1;
	}
	if (cmd->pipe_exist)
	{
		pipe(m->pipe);
		*fd_in = m->pipe[0];
		*fd_out = m->pipe[1];
	}
	if (m->pipe[1] == -1)
		*fd_out = 1;
	dup2(*fd_out, 1);
	if (m->pipe[1] != -1)
	{
		close(m->pipe[1]);
		m->pipe[1] = -1;
	}
	return (OK);
}

int	fd_restore(t_main *m)
{
	dup2(m->backup_fd_in, 0);
	dup2(m->backup_fd_out, 1);
	return (OK);
}	

int	executor(t_main *m)
{
	t_cmd *tmp;
	int		fd_in;
	int		fd_out;

	fd_in = 0;
	fd_out = 1;
	tmp = m->cmd;
	while (tmp)
	{
		do_pipe(m, tmp, &fd_in, &fd_out);
		if (builtin_check(tmp))
		{
			if (cd_b(tmp) == ERROR)
				return (ERROR);
		}
		else
		{
			if (execute(m, tmp, m->info.env) == ERROR)
				return (ERROR);
		}
		fd_restore(m);
		tmp = tmp->next;
	}
	return (OK);
}