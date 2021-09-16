#include "microshell.h"

void	count_cmds(t_main *m)
{
	int		i;

	i = 1;
	if (m->info.argc > 2)
		while (++i < m->info.argc - 1)
			if (!strcmp(m->info.argv[i], ";"))
				m->info.num_of_cmds++;
}

int	parser(t_main *m)
{
	count_cmds(m);
	return (OK);
}