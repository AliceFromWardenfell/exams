#include "microshell.h"

int	builtin_check(t_main *m)
{
	if (!strcmp(m->cmd->args[0], "cd"))
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
	printf("dir has been changed to %s\n", cmd->args[1]);
	return (OK);
}

int	executor(t_main *m)
{
	t_cmd *tmp;

	tmp = m->cmd;
	while (tmp)
	{
		if (builtin_check(m))
		{
			if (cd_b(tmp) == ERROR)
				return (ERROR);
		}
		else
			printf("not builtin\n");
		tmp = tmp->next;
	}
	return (OK);
}