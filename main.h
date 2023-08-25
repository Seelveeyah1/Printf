#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define FLAG_PLUS   (1 << 0)
#define FLAG_SPACE  (1 << 1)
#define FLAG_HASH   (1 << 2)

#define LENGTH_MODIFIER_L 'l'
#define LENGTH_MODIFIER_H 'h'

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
int _print_conversions(char specifier, va_list args,
char *buffer, int *buffer_index);

int print_string_with_escape(char *str, char *buffer,
int *buffer_index);

int print_custom_conversion(char specifier, va_list args,
char *buffer, int *buffer_index);

int print_pointer_address(void *ptr, char *buffer, int *buffer_index);

int print_signed_int(va_list args, char *buffer,
int *buffer_index, char flags);

int prints_unsigned_int(va_list args, char *buffer,
int *buffer_index, char flags);

int prints_octal(va_list args, char *buffer, int *buffer_index, char flags);

int prints_hexadecimal(va_list args, char *buffer,
int *buffer_index, char flags);

int _prints_conversions(const char *format, char specifier,
va_list args, char *buffer, int *buffer_index);

int _print_signed_int(va_list args, char *buffer,
int *buffer_index, char flags, char length_modifier);

int _print_unsigned_int(va_list args, char *buffer,
int *buffer_index, char flags, char length_modifier);

static int prints_string(va_list args, char *buffer,
int *buffer_index, char flags, char length_modifier, int field_width);

static char parse_flags(const char **format);
static int parse_field_width(const char **format);
static char parse_length_modifier(const char **format);
static int parse_precision(const char **format);

int print_strings(va_list args, char *buffer, int 
*buffer_index, char flags, char length_modifier, int 
field_width, int precision);


#endif /* MAIN_H */
