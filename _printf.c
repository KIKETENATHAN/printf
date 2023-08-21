#include "main.h"

int _printf(const char *format, ...)
{
	int ch_print = 0;
	va_list ls_args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(ls_args, format);
	
	while (*format) /* iterate through characters of the format string */
	{
		if (*format != '%')
		{
			write(1, format, 1); /* write character to standard output */
			ch_print++;
		}
		else /* if format is the % sign */
		{
			format++; /* skip '%' check next character */
			if (*format == '\0')
				break;
			if (*format == '%') /* solves %% */
			{
				/* handle '%%' */
				write(1, format, 1);
				ch_print++;
			}
			else if (*format == 'c')
			{
				/* handle '%c' */
				char c = va_arg(ls_args, int);
				write(1, &c, 1);
				ch_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(ls_args, char*);
				int str_len = 0;

				/* calculate length of string to stdoutput */
				while (str[str_len] != '\0')
					str_len++;
				/* write the string to the stdoutput */
				write(1, str, str_len);
				ch_print += str_len;
			}
		}
		format++;
	}
	va_end(ls_args);
	return (ch_print);
}
