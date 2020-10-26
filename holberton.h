#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct placement - keeps track of total count
 * @i: place in buffer
 * @count: total times refreshed
 */

typedef struct placement
{
	int i;
	int count;
} placement;

void icount(char *buffer, struct placement *place);
int _write(char *buffer, int n);
placement *placeholder(void);
int _printf(const char *format, ...);
int choose(const char c, va_list ap, char *buffer, placement *place);
int printint(int n, char *buffer, placement *place);
int printchar(char c, char *buffer, placement *place);
int printstr(char *str, char *buffer, placement *place);

#endif /* HOLBERTON_H */
