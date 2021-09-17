#include "microshell.h"

int	pre_check(t_main *m)
{
	int		i;

	if (m->info.argc == 1) //check if there is at leat 1 cmd
		return (print_error("no args"));
	if (!strcmp(m->info.argv[1], ";")) //check if ";" is not the 1st arg
		return (print_error("\":\" is the 1st arg"));
	i = 0;
	while (++i < m->info.argc - 1) //check if there is no two ";" near each other
		if (!strcmp(m->info.argv[i], ";") && !strcmp(m->info.argv[i + 1], ";"))
			return (print_error("two \";\" near each other"));
	if (!strcmp(m->info.argv[m->info.argc - 1], ";")) // check if ";" is the last
		m->info.argc--;
	return (OK);
}

int	amount_of_cmds(t_main *m)
{
	int		i;
	int		res;

	res = 1;
	i = 0;
	while (++i < m->info.argc)
		if (!strcmp(m->info.argv[i], ";") || !strcmp(m->info.argv[i], "|"))
			res++;
	return (res);
}

// int	make_cmd(t_main *m)
// {
	
// 	return (OK);
// }

int	create_list(t_main *m, int num_of_cmds)
{
	int		i;

	i = -1;
	while (++i < num_of_cmds)
	{
		ft_lstadd_back(&m->cmd, ft_lstnew(1));
	}
	return (OK);
}

int	parser(t_main *m)
{
	if (pre_check(m))
		return (ERROR);
	printf("amout_of_cmds = %d\n", amount_of_cmds(m));
	create_list(m, amount_of_cmds(m));
	while (m->cmd)
	{
		printf("pipe = %d, num_of_args = %d\n", m->cmd->pipe_exist, m->cmd->argc);
		printf("next addr = %p\n", m->cmd->next);
		m->cmd = m->cmd->next;
	}
	// make_cmd(m);
	return (OK);
}