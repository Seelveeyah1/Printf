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
 * print_number_long - Prints a long number to stdout using a specified base.
 * @n: The number to print.
 * @base: The base for conversion (e.g., 10 for decimal,
 * 2 for binary).
 * @is_signed: Indicates whether the number is signed
 * (1) or unsigned (0).
 *
 * Return: The number of characters printed.
 */
int print_number_long(long n, unsigned int base, int is_signed)
{
	int count = 0;

	if (is_signed && n < 0)
	{
		count += print_char('-');
		n = -n;
	}

	if (n / base)
		count += print_number_long(n / base, base, is_signed);

	char digit = (n % base < 10) ? (n % base + '0') : (n % base - 10 + 'a');

	count += print_char(digit);

	return (count);
}
