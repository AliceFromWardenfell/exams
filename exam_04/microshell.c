#include "microshell.h"

int	initialization(t_main *m, int argc, char ** argv)
{
	m->info.argc = argc;
	m->info.argv = argv;
	m->info.num_of_cmds = 1;
	return (OK);
}

int	main(int argc, char **argv)
{
	t_main m;

	initialization(&m, argc, argv);
	parser(&m);
	printf("num of cmds: %d\n", m.info.num_of_cmds);
	return (OK);
}
