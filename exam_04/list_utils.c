#include "microshell.h"

t_cmd	*ft_lstnew(t_main *m, int argc, int gl)
{
	t_cmd	*new_cmd;
	int		i;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		fatal_error();
	new_cmd->args = (char **)malloc((argc + 1) * sizeof(char *));
	if (!new_cmd->args)
		fatal_error();
	i = 0;
	while (i < argc)
		new_cmd->args[i++] = ft_strdup(m->info.argv[gl++]);
	new_cmd->args[i] = NULL;
	new_cmd->pipe_exist = FALSE;
	if (gl < m->info.argc && !strcmp(m->info.argv[gl], "|"))
		new_cmd->pipe_exist = TRUE;
	new_cmd->next = NULL;
	new_cmd->pid = -1;
	new_cmd->argc = argc;
	return (new_cmd);
}

void	ft_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
}
