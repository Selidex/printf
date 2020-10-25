#include "holberton.h"

/**
 * choose - selects function pointer
 * @c: selector
 * @ap: arguments
 * Return: count of chars printed
 */

int choose(const char c, va_list ap)
{
	char r;

	switch (c)
	{
	case 'c':
		return (printchar(va_arg(ap, int)));
	case 's':
		return (printstr(va_arg(ap, char *)));
	case 'i': case 'd':
		return (printint(va_arg(ap, int)));
	case '%':
		r = '%';
		write(1, &r, 1);
		return (1);
	default:
		r = '%';
		write(1, &r, 1);
		write(1, &c, 1);
		return (2);
	}
}
