#include "holberton.h"

/**
 * choose - selects function pointer
 * @c: selector
 * @ap: arguments
 * @buffer: buffer to print
 * @i: location within buffer
 * Return: count of chars printed
 */

int choose(const char c, va_list ap, char *buffer, int *i)
{
	char r;

	switch (c)
	{
	case 'c':
		return (printchar(va_arg(ap, int), buffer, i));
	case 's':
		return (printstr(va_arg(ap, char *), buffer, i));
	case 'i': case 'd':
		return (printint(va_arg(ap, int), buffer, i));
	case '%':
		r = '%';
		buffer[*i] = r;
		(*i)++;
		return (1);
	default:
		r = '%';
		buffer[*i] = r;
		(*i)++;
		buffer[*i] = c;
		(*i)++;
		return (2);
	}
}
