#include "microshell.h"

void	ft_putchar_er(char c)
{
	write(2, &c, 1);
}

int		ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_er(char* str)
{
	int		i = -1;

	while (++i < ft_strlen(str))
		ft_putchar_er(str[i]);
}

char	*ft_strdup(const char *str)
{
	int		index;
	char	*cp;

	if (!(cp = (char*)malloc((ft_strlen(str) + 1) * sizeof(*str))))
		fatal_error();
	index = 0;
	while (index != ft_strlen(str))
	{
		cp[index] = str[index];
		index++;
	}
	cp[index] = '\0';
	return (cp);
}
