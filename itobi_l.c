#include "holberton.h"

/**
 * itox_l - converts long int to hex
 * @n: unsigned int
 * @buffer: buffer
 * @place: place in buffer
 * @c: x or X to determine case
 * Return: count
 */

int itox_l(unsigned long int n, char *buffer, placement *place, const char c)
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
