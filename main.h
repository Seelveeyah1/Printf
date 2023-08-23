#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char c);
int print_string(char *str);
int print_number(int n);
int print_number_unsigned(unsigned int n, unsigned int base);
int _print_conversion(char specifier, va_list args);

#endif /* MAIN_H */
