#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;

	while (get_next_line(&line))
	{
		printf("%s\n", line);
	}
	printf("%s\n", line);
	return(0);
}
