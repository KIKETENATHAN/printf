#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - print variable formats
 * @format: format
 * Return: printed value
 */

int _printf(const char *format, ...)
{
	va_list args;
	int n;
	int x;

	va_start(args, format);
	n = 0;
	while (format[n])
	{
		if (format[n] == '%')
		{
			n++;
			switch (format[n])
			{
				case 'd':
					x = va_arg(args, int);
					printf("%d", x);
					break;
				case 'i':
					x = va_arg(args, int);
					printf("%d", x);
					break;
				default:
					putchar(format[n]);
					break;
			}
		}
		else
		{
			putchar(format[n]);
		}
		n++;
	}
	va_end(args);
	return (0);
}
