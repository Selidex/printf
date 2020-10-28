#include "holberton.h"

/**
 * findflag - finds flags, field width, and precision
 * @format: format
 * @j: placement in format
 * @w: width
 * @p: precision
 * Return: 1
 */

int findflag(char *format, char *buffer, placement *place, va_list ap)
{
	int j, j2, itr, w, p;
	int bpl = 0, bmin = 0, bspc = 0, bpnd = 0, b0 = 0;
	int bl = 0, bint = 0, btag = 0, bcon = 0;
	char pads[] = {'#', '0', '-', ' ', '+'};
	char length[] = {'l', 'h'};
	char tag[] = {'d', 'i', 'o', 'u', 'x', 'X', 'c', 's', 'p', '%'};
	char flag[7];

	for (j = 0; bt != 1 && bc == 0; j++)
	{
		for (j2 = 0; j2 < 5; j2++)
		{
			if (format[j] == pad[j2])
			{
				flag[0] = pad[j2];
			}
		}
	}
}
