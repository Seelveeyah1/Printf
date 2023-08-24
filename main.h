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
int print_number_long(long n, unsigned int base, int is_signed);
int print_unsigned_int(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int _print_conversions(char specifier, va_list args, char *buffer, int *buffer_index);
int print_string_with_escape(char *str, char *buffer, int *buffer_index);
int print_custom_conversion(char specifier, va_list args, char *buffer, int *buffer_index);

#endif /* MAIN_H */
