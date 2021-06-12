#include <stdio.h>

int	ft_printf(char const *format, ...);

int	main(void)
{
	char	*format;
	char	*str;

	format = "OUT: %10.2s\n";
	str = NULL;
	ft_printf(format, str);
	printf(format, str);
	return (0);
}
