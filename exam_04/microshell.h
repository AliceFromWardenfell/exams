#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h> //remove

# define OK 0
# define TRUE 1
# define FALSE 0
# define ERROR 1
# define FATAL 2


typedef struct	s_cmd
{
	int				pipe_exist;
	char			**args;
	int				argc;
	pid_t			pid;
	struct s_cmd	*next;
} 				t_cmd;

typedef struct	s_info
{
	int			argc;
	char		**argv;
	char		**env;
} 				t_info;

typedef struct s_main {
	int				backup_fd_in;
	int				backup_fd_out;
	int				pipe[2];
	struct s_info	info;
	struct s_cmd	*cmd;
} t_main;

int		parser(t_main *m);
int		executor(t_main *m);
void	ft_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd	*ft_lstnew(t_main *m, int argc, int i);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		print_error(char *str);
int		fd_restore(t_main *m);
void	ft_putstr_er(char* str);
void	fatal_error(void);
int		print_error_cd(char *str);

#endif