#include <unistd.h>

int	main(int argc, char **argv)
{
	int	was_not_printed;	
	int	i;
	int	j;
	int	end_line;
	int	len;

	end_line = '\n';
	if (argc != 3)
		write(1, &end_line, 1);
	else
	{
		was_not_printed = 1;
		i = 0;
		while(argv[1][i])
		{
			j = i - 1;
			while(j >= 0)
			{
				if (argv[1][i] == argv[1][j])
					was_not_printed = 0;
				j--;
			}
			if (was_not_printed)
                               	write(1, &argv[1][i], 1);
			was_not_printed = 1;
			i++;
		}
		len = i;
		i = 0;
		while (argv[2][i])
		{
			j = i - 1;
                        while(j >= 0)
                        {
                                if (argv[2][i] == argv[2][j])
                                        was_not_printed = 0;
				j--;
                        }
			j = len - 1;
                        while(j >= 0)
                        {
                                if (argv[1][j] == argv[2][i])
                                        was_not_printed = 0;
				j--;
                        }
			if (was_not_printed)
				write(1, &argv[2][i], 1);
			was_not_printed = 1;
			i++;
		}
		write(1, &end_line, 1);
	}
	return(0);
}
