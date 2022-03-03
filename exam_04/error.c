#include "microshell.h"

int	print_error(char *str)
{
	ft_putstr_er("error: cannot execute ");
	ft_putstr_er(str);
	ft_putstr_er("\n");
	return (ERROR);
}

int	print_error_cd(char *str)
{
	ft_putstr_er("error: cd: bad arguments");
	if (str)
		ft_putstr_er(str);
	ft_putstr_er("\n");
	return (ERROR);
}

void	fatal_error(void)
{
	ft_putstr_er("error: fatal\n");
	exit (FATAL);
}
