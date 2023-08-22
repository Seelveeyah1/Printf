#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
void print_char(char c, int *count);
void print_string(const char *str, int *count);
int format_handler(const char *format, va_list args);
int print_integer(int value);
int _putchar(char c);
int print_binary(unsigned int value);

#endif
