#include "holberton.h"

/**
 * choose - selects function pointer
 * @c: selector
 * @ap: arguments
 * @buffer: buffer to print
 * @i: location within buffer
 * Return: count of chars printed
 */

int choose(const char c, va_list ap, char *buffer, placement *place)
{
	char r;

	switch (c)
	{
	case 'c':
		return (printchar(va_arg(ap, int), buffer, place));
	case 's':
		return (printstr(va_arg(ap, char *), buffer, place));
	case 'i': case 'd':
		return (printint(va_arg(ap, int), buffer, place));
	case '%':
		r = '%';
		buffer[place->i] = r;
		icount(buffer, place);
		return (1);
	default:
		r = '%';
		buffer[place->i] = r;
		icount(buffer, place);
		buffer[place->i] = c;
		icount(buffer, place);
		return (2);
	}
}
