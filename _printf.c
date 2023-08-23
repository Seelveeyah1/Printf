#include "main.h"

/**
 * print_char - Prints a character to stdout.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string to stdout.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int count = 0;

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}

	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *str_arg;

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
		format++;
	if (*format == 'c')
	{
		count += print_char(va_arg(args, int));
	}
	else if (*format == 's')
	{
		str_arg = va_arg(args, char *);
		if (str_arg == NULL)
			str_arg = "(null)";
		count += print_string(str_arg);
	}
	else if (*format == '%')
	{
		count += print_char('%');
	}
	}
	else
	{
		count += write(1, format, 1);
	}
	format++;
	}

	va_end(args);

	return (count);
}
