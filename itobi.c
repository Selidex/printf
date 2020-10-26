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
