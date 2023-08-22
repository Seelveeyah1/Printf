#include <unistd.h>
#include <stdlib.h>
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
	if (*format == '%' && *(format + 1) == 'b')
	{
	unsigned int value = va_arg(args, unsigned int);

	count += print_binary(value);
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
 * print_binary - Prints an unsigned int in binary format
 * @value: The unsigned int to print
 * Return: Number of characters printed
 */
int print_binary(unsigned int value)
{
	int binary[32];
	int index = 0;
	int count = 0;
	int i;

	if (value == 0)
	{
		_putchar('0');
		return (1);
	}

	while (value > 0)
	{
		binary[index++] = value % 2;
		value /= 2;
	}

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
		count++;
	}

	return (count);
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success, 1. On error, -1 is returned.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
