#include "microshell.h"

int	pre_check(t_main *m)
{
	if (m->info.argc == 1) //check if there is at leat 1 cmd
		return (EXIT_SUCCESS);
	if (!strcmp(m->info.argv[m->info.argc - 1], ";")) // check if ";" is the last
		m->info.argc--;
	return (OK);
}


int	count_args(t_main *m, int i)
{
	int		res;

	res = 0;
	while (i < m->info.argc && strcmp(m->info.argv[i], ";") && strcmp(m->info.argv[i], "|"))
	{
		i++;
		res++;
	}
	return (res);
}

int	make_cmd(t_main *m)
{
	int		gl;

	gl = 1;
	while (gl < m->info.argc)
	{
		if (!strcmp(m->info.argv[gl], ";"))
			gl++;
		else
		{
			ft_lstadd_back(&m->cmd, ft_lstnew(m, count_args(m, gl), gl));
			gl += count_args(m, gl) + 1;
		}
	}
	return (OK);
}

int	parser(t_main *m)
{	
	// int		i;
	// t_cmd	*tmp;

	if (pre_check(m))
		return (ERROR);
	if (make_cmd(m))
		return (ERROR);
	// tmp = m->cmd;
	// while (tmp)
	// {
	// 	i = -1;
	// 	printf("pipe = %d, pid = %d, next = %p\n", tmp->pipe_exist, tmp->pid, tmp->next);
	// 	while (++i < tmp->argc)
	// 		printf("argv[%d] = %s\n", i, tmp->args[i]);
	// 	printf("\n");
	// 	tmp = tmp->next;
	// }
	return (OK);
}