#include "holberton.h"

/**
 * leopard - printed this way: \x, followed by the ASCII code value in hexa
 * @c: char
 * @buffer: buffer
 * @place: place in buffer
 * Return: place
 */

int leopard(char *c, char *buffer, placement *place)
{
	int j;

	for (j = 0; c[j] != '\0'; j++)
	{
		if (c[j] < 32 || c[j] >= 127)
		{
			buffer[place->i] = '\\';
			icount(buffer, place);
			buffer[place->i] = 'x';
			icount(buffer, place);
			if (c[j] < 16)
			{
				buffer[place->i] = '0';
				icount(buffer, place);
			}
			itox(c[j], buffer, place, 'X');
		}
		else
		{
			buffer[place->i] = c[j];
			icount(buffer, place);
		}
	}
	return (1);
}

/**
 * address - prints address of pointer
 * @ptr: pointer
 * @buffer: buffer
 * @place: place in buffer
 * Return: 1
 */

int address(void *ptr, char *buffer, placement *place)
{
	unsigned long int k = (unsigned long int)ptr;

	buffer[place->i] = '0';
	icount(buffer, place);
	buffer[place->i] = 'x';
	icount(buffer, place);
	itox_l(k, buffer, place, 'x');


	return (1);
}
