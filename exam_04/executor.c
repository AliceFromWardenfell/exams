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
		return (print_error_cd(0));
	if (chdir(cmd->args[1]) == -1)
	{
		ft_putstr_er("error: cd: cannot change directory to ");
		ft_putstr_er(cmd->args[1]);
		ft_putstr_er("\n");
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
			if (close(m->pipe[0]) == -1)
				fatal_error();
		if (m->pipe[1] != -1)
			if (close(m->pipe[1]) == -1)
				fatal_error();
		execve(cmd->args[0], cmd->args, env);
		print_error(cmd->args[0]);
		exit(OK);
	}
	return (OK);
}

int	do_pipe(t_main *m, t_cmd *cmd, int *fd_in, int *fd_out)
{
	if (m->pipe[0] == -1)
		*fd_in = 0;
	if (dup2(*fd_in, 0) == -1)
		fatal_error();
	if (m->pipe[0] != -1)
	{
		if (close(m->pipe[0]) == -1)
			fatal_error();
		m->pipe[0] = -1;
	}
	if (cmd->pipe_exist)
	{
		if (pipe(m->pipe) == -1)
			fatal_error();
		*fd_in = m->pipe[0];
		*fd_out = m->pipe[1];
	}
	if (m->pipe[1] == -1)
		*fd_out = 1;
	if (dup2(*fd_out, 1) == -1)
		fatal_error();
	if (m->pipe[1] != -1)
	{
		if (close(m->pipe[1]) == -1)
			fatal_error();
		m->pipe[1] = -1;
	}
	return (OK);
}

int	fd_restore(t_main *m)
{
	if (dup2(m->backup_fd_in, 0) == -1)
		fatal_error();
	if (dup2(m->backup_fd_out, 1) == -1)
		fatal_error();
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
			cd_b(tmp);
		else
			execute(m, tmp, m->info.env);
		fd_restore(m);
		if (!tmp->pipe_exist)
		{
			if (tmp->pid != -1 && tmp->pid != 0)
				if (waitpid(tmp->pid, NULL, 0) == -1)
					fatal_error();
			tmp->pid = -1;
		}
		tmp = tmp->next;
	}
	return (OK);
}
