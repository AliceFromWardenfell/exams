#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*rez;
	int	i;
	
	i = 0;
	while (str1[i])
		i++;
	rez = (char*)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (str1[i])
	{
		rez[i] = str1[i];
		i++;
	}
	rez[i] = str2[0];
	i++;
	rez[i] = '\0';
	free(str1);
	return (rez);
}

int	get_next_line(char **line)
{
	char buf[2];

	if (!line || read(0, NULL, 0) == -1)
		return(-1);
	*line = (char*)malloc(1);
	**line = '\0';
	while(read(0, buf, 1) > 0)
	{
		buf[1] = '\0';
		if (buf[0] == '\n')
			return(1);
		*line = ft_strjoin(*line, buf);
	}
	return(0);
}
