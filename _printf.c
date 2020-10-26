#include "holberton.h"

/**
 * icount - counts chars printed
 * @buffer: times going through buffer
 * @place: place in buffer
 * Return: void
 */

void icount(char *buffer, struct placement *place)
{
	if (place->i < 1023)
		(place->i)++;
	else
	{
		_write(buffer, place->i);
		place->i = 0;
		(place->count)++;
	}
}

/**
 * _write - writes buffer
 * @buffer: buffer to print
 *@n: size of the buffer printed
 * Return: count of characters
 */

int _write(char *buffer, int n)
{
	return (write(1, buffer, n));
}

/**
 * placeholder - initializes struct place
 * Return: place
 */

placement *placeholder(void)
{
	placement *place;

	place = malloc(sizeof(placement));
	if (place == NULL)
		return (NULL);
	place->i = 0;
	place->count = 0;
	return (place);
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
	int count = 0, j = 0;
	char *buffer;
	struct placement *place;

	buffer = malloc(1024);
	if (!buffer)
		return (-1);
	place = placeholder();
	if (!place)
		return (-1);
	if (format == NULL)
		return (0);
	va_start(ap, format);
	for (; format[j] != '\0'; j++)
	{
		if (format[j] == '%')
		{
			count += choose(format[j + 1], ap, buffer, place);
			j++;
		}
		else
		{
			buffer[place->i] = format[j];
			icount(buffer, place);
			count++;
		}
	}
	buffer[place->i] = '\0';
	_write(buffer, place->i);
	if (place->count == 0)
		count = (place->i);
	else
		count = ((place->count * 1024) + place->i);
	free(place);
	free(buffer);
	return (count);
}
