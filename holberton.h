#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int choose(const char c, va_list ap, char *buffer, int *i);
int printint(int n, char *buffer, int *i);
int printchar(char c, char *buffer, int *i);
int printstr(char *str, char *buffer, int *i);

#endif /* HOLBERTON_H */
