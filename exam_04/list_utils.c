#include "microshell.h"

t_cmd	*ft_lstnew(void)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	// new_cmd->args = (char **)malloc(num_of_args * sizeof(char *));
	// new_cmd->argc = num_of_args;
	new_cmd->pipe_exist = FALSE;
	new_cmd->next = NULL;
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
