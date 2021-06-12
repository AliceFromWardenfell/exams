#include <unistd.h>
#include <stdarg.h>

int	nbr_len(long nbr, int base)
{
	int	len;

	len = 1;
	while (nbr >= base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

void	put_nbr(long nbr, int base, char *charset)
{
	if (nbr >= base)
		put_nbr(nbr / base, base, charset);
	write(1, &charset[nbr % base], 1);
}

int	ft_printf(const char *f, ... )
{
	va_list		arg;
	char		*format;
	int		ret;
	int		width;
	int		prec;
	char		*str;
	long		nbr;
	int		spaces;
	int		zeros;
	int		arglen;
	int		sign;

	format = (char *)f;
	ret = 0;
	va_start(arg, f);
	while (*format)
	{
		if (*format == '%')
		{
			width = 0;
                	prec = -1;
                	zeros = 0;
                	spaces = 0;
                	arglen = 0;
                	sign = 0;
			format++;
			while (*format >= '0' && *format <= '9')
			{
				width = width * 10 + (*format - 48);
				format++;
			}
			if (*format == '.')
			{	
				format++;
				prec = 0;
				while (*format >= '0' && *format <= '9')
				{
					prec = prec * 10 + (*format - 48);
					format++;
				}
			}
			if (*format == 's')
			{
				str = va_arg(arg, char *);
				if (!str)
					str = "(null)";
				while (str[arglen])
					arglen++;
			}
			if (*format == 'd')
			{
				nbr = va_arg(arg, int);
				if (nbr < 0)
				{
					nbr = -nbr;
					sign = 1;
				}
				arglen = nbr_len(nbr, 10) + sign;
			}
			if (*format == 'x')
			{
				nbr = va_arg(arg, unsigned int);
				arglen = nbr_len(nbr, 16);
			}
			if (*format != 's' && prec >= arglen)
				zeros = prec - arglen + sign;
			else if (*format == 's' && prec > -1 && prec < arglen)
				arglen = prec;
			else if ((*format == 's' || nbr == 0) && prec == 0)
				arglen = 0;
			spaces = width - zeros - arglen;
			while (spaces-- > 0)
				ret += write(1, " ", 1);
			if (sign)
				write(1, "-", 1);
			while (zeros-- > 0)
				ret += write(1, "0", 1);
			if (*format == 's')
				write(1, str, arglen);
			if (*format == 'd' && arglen > 0)
				put_nbr(nbr, 10, "0123456789");
			if (*format == 'x' && arglen > 0)
				put_nbr(nbr, 16, "0123456789abcdef");
			ret += arglen;
		}
		else
			ret += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return(ret);	
}	
