#include "holberton.h"

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
*tag - handles finding conversion specifiers
*@form: the char being tested
*@flag: all flags currently found
*@fakebool: struct of fake boolians
*/
void tag(char form, char *flag, fakebool *t)
{
	int j;
	char tag[] = {'d', 'i', 'o', 'u', 'x', 'X', 'c', 's', 'p'};

	for (j = 0; btag == 0 && j < 9; j++)
	{
		if (form == tag[j])
		{
			flag[6] = format[j];
			t->btag = 1;
		}
	}
}

/**
 *lh - checks for l or h flags
 *@form: the letter being checked
 *@flag: array of existing flags
 *@fakebool: group of fake bools
 *Return: void no return
 */
void lh(char form, char *flag, fakebool *t)
{
	if ((form == 'l' || form == 'h') && t->l != 0)
	{
		t->bcon = 1;
	}
	else if(form == 'l' || form == 'h')
	{
		flag[5] = form[j];
		t->l = 1;
	}
}

/**
 *digit - handles number flags
 *@form: string of potential tags
 *@flag: array of already discovered flags
 *@t: group of fake boolians
 *Return: the number that form has been incremented
 */
int digit(char *form, char *flag, fakebool *t)
{
	int j = 0;
	if ((form[j] >= '0' && form[j] <= '9') && t->l != 0)
		t->bcon = 1;
	else if ((form[j] >= '0' && form[j] <= '9') && t->d == 0)
		for (; form[j] >= '0' && form[j] <= '9'; j++)
				t->w = (t->w * 10) + (form[j] - '0');
	if (form[j] == '.' && (t->d != 0 || t->l != 0))
		t->bcon = 1;
	else if (form[j] == '.')
	{
		for (; form[j] >= '0' && form[j] <= '9'; j++)
			t->p = (t->p * 10) + (form[j] - '0');
		t->d = 1;
	}
	return (j);
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
	int j;
	char flag[7] = {'z', 'z', 'z', 'z', 'z', 'z', 'z'};
	fakebool *test;

	test = maker();
	for (j = 0; test->btag == 0 && form[j] != '\0'; j++)
	{
		if (form[j] != 'l' && form[j] != 'h')
		{

		}
		pad(form[j], flag, test);
		j += digit((form + j), flag, test);
		lh(form[j], flag, test);
		tag(form[j], flag, test);
		if (form[j] == '%')
			return (j + choose('%', ap, buffer, place));
		if (test->bcon == 1)
		{

		}
	}
	if (form[j] == '\0')
		return (-1);
}
