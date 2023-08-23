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
 * print_number_unsigned - Prints a number to stdout.
 * @n: The number to print.
 * @base: The base for conversion
 * (e.g., 10 for decimal, 2 for binary).
 *
 * Return: The number of characters printed.
 */
int print_number_unsigned(unsigned int n, unsigned int base)
{
	int count = 0;

	if (n / base)
		count += print_number_unsigned(n / base, base);

	char digit = (n % base < 10) ? (n % base + '0') : (n % base - 10 + 'a');

	count += print_char(digit);

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

		count += print_number_unsigned(int_arg, 10);
	}
	else if (specifier == 'b')
	{
		unsigned int binary_arg = va_arg(args, unsigned int);

		count += print_number_unsigned(binary_arg, 2);
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
