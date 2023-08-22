#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Print a single character
 * @c: The character to print
 * @count: Pointer to the character count
 */
void print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * print_string - Print a string
 * @str: The string to print
 * @count: Pointer to the character count
 */
void print_string(const char *str, int *count)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*count)++;
	}
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
		format++; // Move past '%'
	if (*format == 'c')
	{
		char c = va_arg(args, int);

		print_char(c, &count);
	}
	else if (*format == 's')
	{
		char *str = va_arg(args, char *);

		if (str)
		{
			print_string(str, &count);
		}
	}
	else if (*format == '%')
	{
		print_char('%', &count);
	}
	}
	else
	{
		print_char(*format, &count);
	}
	format++;
	}

	va_end(args);

	return (count);
}
