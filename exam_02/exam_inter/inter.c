#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	was_not_printed;	
	int	is_in_both;
	int	i;
	int	j;
	int	end_line;

	end_line = '\n';
	if (argc != 3)
		write(1, &end_line, 1);
	else
	{
		was_not_printed = 1;
		is_in_both = 0;
		i = 0;
		while(argv[1][i])
		{
			j = i - 1;
			while(j >= 0)
			{
				//printf("argv[1][i] = %c, argv[1][j] = %c, i = %d, j = %d, was_not_printed = %d, is_in_both = %d\n", argv[1][i], argv[1][j], i, j, was_not_printed, is_in_both);
				if (argv[1][i] == argv[1][j])
					was_not_printed = 0;
				j--;
			}
			j = 0;
			while (argv[2][j])
			{
				//printf("argv[1][i] = %c, argv[2][j] = %c, i = %d, j = %d, was_not_printed = %d, is_in_both = %d\n", argv[1][i], argv[2][j], i, j, was_not_printed, is_in_both);
				if (argv[1][i] == argv[2][j])
					is_in_both = 1;
				j++;
			}
			/*printf("was_not_printed = %d, is_in_both = %d\n", was_not_printed, is_in_both);*/
			//write(0, "\n", 1);
			if (was_not_printed && is_in_both)
				write(0, &argv[1][i], 1);
			was_not_printed = 1;
                	is_in_both = 0;
			i++;
		}
		write(1, &end_line, 1);
	}
	return(0);
}
