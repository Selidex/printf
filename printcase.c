#include "holberton.h"

/**
 * printchar - prints char
 * @c: char to print
 * @buffer: buffer to print
 * @place: place in buffer
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
 * @place: place in buffer
 * Return: count of chars printed
 */

int printstr(char *str, char *buffer, placement *place)
{
	int j;

	if (str == NULL)
	{
		str = "(null)";
	}
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
 * @place: place in buffer
 * Return: count of chars printed
 */

int printint(int n, char *buffer, placement *place)
{
	int b = 0, min = 0, k, count = 1;
	char neg = '-';

	if (n == -2147483648)
	{
		min = 1;
		n = n / 10;
	}
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
	if (min == 1)
	{
		buffer[place->i] = '8';
		icount(buffer, place);
	}
	return (count);
}

/**
 * rot - converts string to ROT13
 * @str: string
 * @buffer: buffer
 * @place: place in buffer
 * Return: chars
 */

int rot(char *str, char *buffer, placement *place)
{
	int j;

	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j] != '\0'; j++)
	{
		if ((str[j] >= 65 && str[j] <= 77) || (str[j] >= 97 && str[j] <= 109))
			buffer[place->i] = str[j] + 13;
		else if ((str[j] >= 78 && str[j] <= 90) || (str[j] >= 110 && str[j] <= 122))
			buffer[place->i] = str[j] - 13;
		else
			buffer[place->i] = str[j];
		icount(buffer, place);
	}
	return (j);
}

/**
 *rev - prints a string in reverse
 *@str: the string to reverse
 *@buffer: place to write code
 *@place: index in buffer
 *Return: number of things printed
 */

int rev(char *str, char *buffer, placement *place)
{
	if (str == NULL)
		return (0);

	if (*(str + 1) != '\0')
		rev((str + 1), buffer, place);
	buffer[place->i] = *str;
	icount(buffer, place);
	return (0);

}
