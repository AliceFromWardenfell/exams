#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <string.h>
# include <stdio.h> //remove

# define OK 0

typedef struct	s_info
{
	int			argc;
	char		**argv;
	int			num_of_cmds;
} 				t_info;

typedef struct s_main {
	struct s_info	info;
} t_main;

int	parser(t_main *m);

#endif