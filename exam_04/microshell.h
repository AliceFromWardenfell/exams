#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h> //remove

# define OK 0
# define TRUE 1
# define FALSE 0
# define ERROR 1

typedef struct	s_cmd
{
	int				pipe_exist;
	char			**args;
	int				argc;
	struct s_cmd	*next;
} 				t_cmd;

typedef struct	s_info
{
	int			argc;
	char		**argv;
	int			num_of_cmds;
} 				t_info;

typedef struct s_main {
	struct s_info	info;
	struct s_cmd	*cmd;
} t_main;

int		parser(t_main *m);
void	ft_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd	*ft_lstnew(int num_of_args);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		print_error(char *str);

#endif