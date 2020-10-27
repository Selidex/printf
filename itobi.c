#include "holberton.h"

/**
 *itob - converts an unsigned int to binary and prints it
 *@n: the int to be printed as binary
 *@buffer: place to print
 *@place: index in buffer
 *Return: the number of digits printed
 */

int itob(unsigned int n, char *buffer, placement *place)
{
	int i, count, k;
	unsigned int bit[32];

	if (n == 0)
	{
		buffer[place->i] = '0';
		icount(buffer, place);
		return (1);
	}

	for (i = 0; i < 32; i++)
		bit[i] = 0;
	for (i = 31; n > 0; i--)
	{
		bit[i] = n % 2;
		n /= 2;
	}
	for (i = 0; bit[i] != 1; i++)
	{}
	while (i < 32)
	{
		k = bit[i] + '0';
		buffer[place->i] = k;
		icount(buffer, place);
		i++;
		count++;
	}
	return (count);
}

/**
 *itoo - converts decimal to octal
 *@n: number being converted
 *@buffer: place to store for write
 *@place: index for buffer
 *Return: number of digits printed
 */

int itoo(unsigned int n, char *buffer, placement *place)
{
	int i, count, k;
	unsigned int bit[32];

	if (n == 0)
	{
		buffer[place->i] = '0';
		icount(buffer, place);
		return (1);
	}

	for (i = 0; i < 32; i++)
		bit[i] = 0;
	for (i = 31; n > 0; i--)
	{
		bit[i] = n % 8;
		n /= 8;
	}
	for (i = 0; bit[i] == 0; i++)
	{}
	while (i < 32)
	{
		k = bit[i] + '0';
		buffer[place->i] = k;
		icount(buffer, place);
		i++;
		count++;
	}
	return (count);
}

/**
 *itox - converts decimal to hex
 *@n: numer to be converted
 *@buffer: the buffer for writing
 *@place: index in buffer
 *@c: test for casewise
 *Return: number of digits printed
 */

int itox(unsigned int n, char *buffer, placement *place, const char c)
{
	int i, count, k;
	unsigned int bit[32];

	if (n == 0)
	{
		buffer[place->i] = '0';
		icount(buffer, place);
		return (1);
	}

	for (i = 0; i < 32; i++)
		bit[i] = 0;
	for (i = 31; n > 0; i--)
	{
		bit[i] = n % 16;
		n /= 16;
	}
	for (i = 0; bit[i] == 0; i++)
	{}
	while (i < 32)
	{
		if (bit[i] < 10)
			k = bit[i] + '0';
		else
		{
			bit[i] -= 10;
			if (c == 'x')
				k = bit[i] + 'a';
			else
				k = bit[i] + 'A';
		}
		buffer[place->i] = k;
		icount(buffer, place);
		i++;
		count++;
	}
	return (count);
}

/**
 *printunint - prints an unsigned int
 *@n: the int to print
 *@buffer: the buffer to write too
 *@place: the index of buffer
 *Return: 1
 */

int printunint(unsigned int n, char *buffer, placement *place)
{
	int k, count = 1;

	if (n / 10 != 0)
		count += printint((n / 10), buffer, place);
	k = (n % 10) + '0';
	buffer[place->i] = k;
	icount(buffer, place);
	return (count);
}
