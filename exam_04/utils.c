#include "microshell.h"

int		ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	int		index;
	char	*cp;

	if (!(cp = (char*)malloc((ft_strlen(str) + 1) * sizeof(*str))))
		return (NULL);
	index = 0;
	while (index != ft_strlen(str))
	{
		cp[index] = str[index];
		index++;
	}
	cp[index] = '\0';
	return (cp);
}
