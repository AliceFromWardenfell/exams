#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_d
{
	char	**to_paint;
	int 	max_w;
	int		max_h;
	char	rec;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
}				t_d;

int		ft_strlen(const char *str) // not protected
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		error_exit(t_d *d, char *str, int code, FILE *fd)
{
	int		i;

	i = 0;
	while (i < d->max_w)
	{
		if (d->to_paint[i])
			free(d->to_paint[i]);
		i++;
	}
	if (d->to_paint)
		free(d->to_paint);
	write(1, str, ft_strlen(str));
	if (fd)
		fclose(fd);
	return (code);
}

int		good_exit(t_d *d, int code, FILE *fd)
{
	int		i;

	i = 0;
	while (i < d->max_w)
	{
		if (d->to_paint[i])
			free(d->to_paint[i]);
		i++;
	}
	if (d->to_paint)
		free(d->to_paint);
	if (fd)
		fclose(fd);
	return (code);
}

int		check_bg(t_d *d)
{
	if (d->max_h < 1 || d->max_h > 300)
		return (1);
	if (d->max_w < 1 || d->max_w > 300)
		return (1);
	return (0);
}

void	init(t_d *d)
{
	d->to_paint = NULL;
	d->max_w = 0;
	d->max_h = 0;
	char rec = '\0';
	float x = 0;
	float y = 0;
	float w = 0;
	float h = 0;
	char c = '\0';
}

int		malloc_to_paint(t_d *d)
{
	int		i;

	i = 0;
	if (!(d->to_paint = (char **)malloc(d->max_w * sizeof(char *))))
		return (1);
	while (i < d->max_h)
	{
		d->to_paint[i] = NULL;
		i++;
	}
	i = 0;
	while (i < d->max_h)
	{
		if (!(d->to_paint[i] = (char *)malloc(d->max_w * sizeof(char))))
			return (1);
		i++;
	}
	return (0);
}

void	fill_bg(t_d *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->max_h)
	{
		j = 0;
		while (j < d->max_w)
		{
			d->to_paint[i][j] = d->c;
			j++;
		}
		i++;
	}
}

void	output(t_d *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->max_h)
	{
		j = 0;
		while (j < d->max_w)
		{
			write(1, &d->to_paint[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		check_data(t_d *d)
{
	if (d->w < 1.00000000 || d->h < 1.00000000
			|| (d->rec != 'R' && d->rec != 'r'))
		return (1);
	return (0);
}

int		in_out_border(t_d *d, int x, int y)
{
	if (x < d->x || y < d->y || x > d->x + d->w || y > d->y + d->h)
		return (0); // out
	if (x - d->x < 1.00000000 || y - d->y < 1.00000000
		|| d->x + d->w - x < 1.00000000 || d->y + d->h - y < 1.00000000)
		return (2); // border
	return (1); // in
	
}

void	fill_data(t_d *d)
{
	int		dot_place;
	int		i;
	int		j;

	i = 0;
	while (i < d->max_h)
	{
		j = 0;
		while (j < d->max_w)
		{
			dot_place = in_out_border(d, j, i);
			if ((d->rec == 'R' && dot_place) ||
				(d->rec == 'r' && dot_place == 2))
				d->to_paint[i][j] = d->c;
			j++;
		}
		i++;
	}
}

int		do_instructions(t_d *d, FILE *fd)
{
	int		ret;

	while ((ret = fscanf(fd, "%c %f %f %f %f %c\n", &d->rec, &d->x, &d->y, &d->w, &d->h, &d->c)) == 6)
	{	
		if (check_data(d))
			return (error_exit(d, "Error: Operation file corrupted\n", 1, fd));
		fill_data(d);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	FILE	*fd;
	int		ret;
	t_d		d;

	init(&d);
	if (argc != 2)
	{
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
		return (1);
	}
	else
	{
		if ((fd = fopen(argv[1], "r")) == NULL)
			return (error_exit(&d, "Error: Operation file corrupted\n", 1, fd));
		if ((ret = fscanf(fd, "%d %d %c\n", &d.max_w, &d.max_h, &d.c)) != 3)
			return (error_exit(&d, "Error: Operation file corrupted\n", 1, fd));
		if (check_bg(&d))
			return (error_exit(&d, "Error: Operation file corrupted\n", 1, fd));
		if (malloc_to_paint(&d))
			return (error_exit(&d, "Error: Memory allocation failed\n", 1, fd));
		fill_bg(&d);
		if (do_instructions(&d, fd))
			return (1);
		output(&d);
	}
	return (good_exit(&d, 0, fd));
}
