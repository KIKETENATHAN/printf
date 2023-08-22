#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *y)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int x, curr_y;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_y = *y + 1; format[curr_y] != '\0'; curr_y++)
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
			if (format[curr_y] == FLAGS_CH[x])
			{
				flags |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CH[x] == 0)
			break;
	}

	*y = curr_y - 1;

	return (flags);
}

