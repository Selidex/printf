#include "holberton.h"

/**
 * printchar - prints char
 * @c: char to print
 * @buffer: buffer to print
 * @i: place in buffer
 * Return: 1
 */

int printchar(char c, char *buffer, placement *place)
{
	buffer[place->i] = c;
	icount(buffer, place);
	return (1);
}

/**
 * printstr - prints string
 * @str: string
 * @buffer: buffer to print
 * @i: place in buffer
 * Return: count of chars printed
 */

int printstr(char *str, char *buffer, placement *place)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
	{
		buffer[place->i] = str[j];
		icount(buffer, place);
	}
	return (j);
}

/**
 * printint - prints int
 * @n: int
 * @buffer: buffer to print
 * @i: place in buffer
 * Return: count of chars printed
 */

int printint(int n, char *buffer, placement *place)
{
	int b = 0, k, count = 1;
	char neg = '-';

	if (n < 0)
	{
		b = 1;
		n = (n * -1);
	}
	if (b == 1)
	{
		buffer[place->i] = neg;
		icount(buffer, place);
		count++;
	}
	if (n / 10 != 0)
		count += printint((n / 10), buffer, place);
	k = (n % 10) + '0';
	buffer[place->i] = k;
	icount(buffer, place);
	return (count);
}
