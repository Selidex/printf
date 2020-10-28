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
int _getflags(const char *format, char *buffer, placement *place, va_list ap);
int _printf(const char *format, ...);
int choose(const char c, va_list ap, char *buffer, placement *place);
int rot(char *str, char *buffer, placement *place);
int rev(char *str, char *buffer, placement *place);
int printint(int n, char *buffer, placement *place);
int printchar(char c, char *buffer, placement *place);
int printstr(char *str, char *buffer, placement *place);
int itob(unsigned int n, char *buffer, placement *place);
int itoo(unsigned int n, char *buffer, placement *place);
int itox(unsigned int n, char *buffer, placement *place, const char c);
int itox_l(unsigned long int n, char *buffer, placement *place, const char c);
int leopard(char *c, char *buffer, placement *place);
int printunint(unsigned int n, char *buffer, placement *place);
int address(void *ptr, char *buffer, placement *place);

#endif /* HOLBERTON_H */
