#include "microshell.h"

// int	make_cmd(t_main *m)
// {
	
// 	return (OK);
// }

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

int	parser(t_main *m)
{
	if (pre_check(m))
		return (ERROR);
	printf("amout_of_cmds = %d\n", amount_of_cmds(m));
	// make_cmd(m);
	return (OK);
}