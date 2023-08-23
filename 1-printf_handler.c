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
 * print_number - Prints a number to stdout.
 * @n: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}

	if (n / 10)
	{
		count += print_number(n / 10);
		count += print_char(n % 10 + '0');
	}

	return (count);
}

/**
 * _print_conversion - Handles a conversion specifier.
 * @specifier: The conversion specifier.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int _print_conversion(char specifier, va_list args)
{
	int count = 0;

	if (specifier == 'c')
	{
		count += print_char(va_arg(args, int));
	}
	else if (specifier == 's')
	{
	char *str_arg = va_arg(args, char *);

	if (str_arg == NULL)
		str_arg = "(null)";
	count += print_string(str_arg);
	}
	else if (specifier == '%')
	{
		count += print_char('%');
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int int_arg = va_arg(args, int);

		count += print_number(int_arg);
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

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
		format++;
		count += _print_conversion(*format, args);
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
