#include "holberton.h"

/**
 * _printf - produces output according to format
 * @format: format of input
 *
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0, i = 0;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			count += choose(format[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	return (count);
}
