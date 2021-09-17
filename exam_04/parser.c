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

int	create_list(t_main *m, int num_of_cmds)
{
	int		i;

	i = -1;
	while (++i < num_of_cmds)
	{
		ft_lstadd_back(&m->cmd, ft_lstnew());
	}
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
	int		i;
	t_cmd	*tmp;

	tmp = m->cmd;
	gl = 1;
	while (gl < m->info.argc)
	{
		tmp->argc = count_args(m, gl);
		tmp->args = (char **)malloc((tmp->argc + 1) * sizeof(char *));
		if (!tmp->args)
			return (ERROR); //handle errors
		i = 0;
		while (i < tmp->argc)
		{
			tmp->args[i] = ft_strdup(m->info.argv[gl]);
			i++;
			gl++;
		}
		tmp->args[i] = NULL;
		if (gl < m->info.argc && !strcmp(m->info.argv[gl], "|"))
			tmp->pipe_exist = TRUE;
		gl++;
		tmp = tmp->next;
	}
	return (OK);
}

int	parser(t_main *m)
{	
	int		i;
	t_cmd	*tmp;

	if (pre_check(m))
		return (ERROR);
	printf("amout_of_cmds = %d\n", amount_of_cmds(m));
	create_list(m, amount_of_cmds(m));
	if (make_cmd(m))
		return (ERROR);
	tmp = m->cmd;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->argc)
			printf("argv[%d] = %s\n", i, tmp->args[i]);
		printf("pipe = %d\n", tmp->pipe_exist);
		tmp = tmp->next;
	}
	return (OK);
}