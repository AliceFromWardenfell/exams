#include "microshell.h"

int	initialization(t_main *m, int argc, char ** argv)
{
	m->info.argc = argc;
	m->info.argv = argv;
	m->info.num_of_cmds = 1;
	m->cmd = NULL;
	return (OK);
}

int	main(int argc, char **argv)
{
	t_main m;

	initialization(&m, argc, argv);
	if (parser(&m))
		return (ERROR);
	return (OK);
}
