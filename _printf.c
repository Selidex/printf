#include "holberton.h"

/**
 * _write - writes buffer
 * @buffer: buffer to print
 * Return: count of characters
 */

int _write(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		write(1, &buffer[i], 1);
	}
	return (i);
}

/**
 * _printf - produces output according to format
 * @format: format of input
 *
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0, *i, j = 0;
	char buffer[1024];

	i = malloc(sizeof(int));
	if (!i)
		return (-1);
	*i = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	for (; format[j] != '\0'; j++)
	{
		if (format[j] == '%')
		{
			count += choose(format[j + 1], ap, buffer, i);
			j++;
		}
		else
		{
			buffer[*i] = format[j];
			(*i)++;
			count++;
		}
	}
	buffer[*i] = '\0';
	count = _write(buffer);
	free(i);
	return (count);
}
