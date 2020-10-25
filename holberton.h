#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int choose(const char c, va_list ap);
int printint(int i);
int printchar(char c);
int printstr(char *str);

#endif /* HOLBERTON_H */
