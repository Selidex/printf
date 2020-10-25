#include "holberton.h"

/**
 * printchar - prints char
 * @c: char to print
 * Return: 1
 */

int printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * printstr - prints string
 * @str: string
 * Return: count of chars printed
 */

int printstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
	}
	return (i);
}

/**
 * printint - prints int
 * @i: int
 * Return: count of chars printed
 */

int printint(int i)
{
	int b = 0, k, count = 1;
	char neg = '-';

	if (i < 0)
	{
		b = 1;
		i = (i * -1);
	}
	if (b == 1)
	{
		write(1, &neg, 1);
		count++;
	}
	if (i / 10 != 0)
		count += printint(i / 10);
	k = (i % 10) + '0';
	write(1, &k, 1);
	return (count);
}
