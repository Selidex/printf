#include "holberton.h"

/**
 *struct fakebool - a grouping of fake bools
 *@bcon: conflict bool
 *@btag: tag bool
 *@l: l/h bool
 *@d: . bool
 *@n: w/p bool
 *@w: width flag
 *@p: precision flag
 */
struct fakebool
{
	int bcon, btag, l, d, n, w, p;
};


/**
 * pad - handles pad based flags
 * @form: format
 * @flag: arry of current flags
 * @t: struct of fake boolians
 * Return: void
 */

void pad(char form, char *flag, fakebool *t)
{
	if (form == '#' && (t->l != 0 || t->n != 0))
		t->bcon = 1;
	else if (form == '#')
		flag[0] = '#';

	if ((form == ' ' || form == '+') && (t->n != 0 || t->l != 0))
		t->bcon = 1;
	else if (form == ' ' || form == '+')
		if (flag[1] == ' ' || flag[1] == 'z')
			flag[1] = form;

	if ((form == '0' || form == '-') && (t->n != 0 || t->l != 0))
		t->bcon = 1;
	else if (form == '0' || form == '-')
		if (flag[2] == '0' || flag[2] == 'z')
			flag[2] = form;
}

/**
 *digit - handles width and precision flags
 *@form: format
 *@flag: array of existing flags
 *@t: fake boolian
 *Return: void no return
 */

void digit(char form, char *flag, fakebool *t)
{
	if ((form >= '0' && form <= '9') && t->l != 0)
		t->bcon = 1;
	else if ((form >= '0' && form <= '9') && d == 0)
		for (; form[j] >= '0' && form[j] <= '9'; j++)
}


/**
 * findflag - finds flags, field width, and precision
 * @form: format
 * @ap: argument list
 * @buffer: place to write
 * @place: index in buffer
 * Return: 1
 */

int findflag(char *form, va_list ap, char *buffer, placement *place)
{
	int j, jp;
	char tag[] = {'d', 'i', 'o', 'u', 'x', 'X', 'c', 's', 'p'};
	char flag[7] = {'z', 'z', 'z', 'z', 'z', 'z', 'z'};
	fakebool *test;
	for (j = 0; test->btag == 0; j++)
	{
		pad(format[j], flag, test);



				for (; form[j] >= '0' && form[j] <= '9'; j++)
				w = (w * 10) + (form[j] - '0');	}

		if (form[j] == '.' && (d != 0 || l != 0))
			bcon = 1;
		else if (form[j] == '.')
		{
			for (; form[j] >= '0' && form[j] <= '9'; j++)
				p = (p * 10) + (form[j] - '0');
			d = 1; }

		if (form[j] == 'l' || form[j] == 'h')
		{
			flag[5] = form[j];
			l = 1; }

		for (j2 = 0; btag == 0 && j2 < 9; j2++)
		{
			if (format[j] == tag[j2])
			{ flag[6] = format[j];
				btag = 1; } }
		if (form[j] == '%')
		{
			buffer[place->i] = '%';
			icount(buffer, place);
			return (j + 1);
		}

		if (bcon == 1)
		{

		}
	}
}
