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
		_write(buffer, 1024);
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
 *_getflags - parses format for flags then sends ot select
 *@format: the format string
 *@buffer: place being printed
 *@place: our print count
 *@ap: list of arguments
 *Return: our print count or -1 on fail
 */

int _getflags(const char *format, char *buffer, placement *place, va_list ap)
{
	int count = 0, j = 0;

	for (; format[j] != '\0'; j++)
	{
		if (format[j] == '%')
		{
			while (format[j + 1] == ' ')
			{
				if (format[j + 2] == '\0')
				{
					return (-1);
				}
				j++;
			}
			if (format[j + 1] == '\0')
			{
				return (-1);
			}
			choose(format[j + 1], ap, buffer, place);
			j++;
		}
		else
		{
			buffer[place->i] = format[j];
			icount(buffer, place);
		}
	}
	buffer[place->i] = '\0';
	_write(buffer, place->i);
	count = ((place->count * 1024) + place->i);
	return (count);
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
	int count = 0;
	char *buffer;
	struct placement *place;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		return (-1);
	place = placeholder();
	if (!place)
		return (-1);
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = _getflags(format, buffer, place, ap);
	va_end(ap);
	free(place);
	free(buffer);
	return (count);
}
