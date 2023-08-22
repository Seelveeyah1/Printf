#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom implementation of printf
 * @format: The format string
 * @...: Variadic arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	count = format_handler(format, args);
	va_end(args);

	return (count);
}

/**
 * format_handler - Handles the format string and arguments
 * @format: The format string
 * @args: Variadic arguments
 * Return: Number of characters printed
 */
int format_handler(const char *format, va_list args)
{
	int count = 0;

	while (format && *format)
	{
	if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
	{
		int value = va_arg(args, int);

		count += print_integer(value);
		format += 2;
	}
	else
	{
		_putchar(*format);
		count++;
		format++;
	}
	}

	return (count);
}

/**
 * print_integer - Prints an integer
 * @value: The integer to print
 * Return: Number of characters printed
 */
int print_integer(int value)
{
	/* Simplified implementation for demonstration */
	return (_printf("%d", value));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
