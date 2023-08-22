#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;
	char current_char = format[curr_i];

	switch (current_char)
	{
		case '.':
			precision = 0;
			curr_i++;
			current_char = format[curr_i];

			while (current_char != '\0')
			{
				if (is_digit(current_char))
				{
					precision *= 10;
					precision += current_char - '0';
					curr_i++;
					current_char = format[curr_i];
				}
				else if (current_char == '*')
				{
					curr_i++;
					precision = va_arg(list, int);
					break;
				}
				else
				{
					break;
				}
			}
			*i = curr_i - 1;
			break;
		default:
			break;
	}
	return (precision);
}
