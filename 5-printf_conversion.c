#include "main.h"

/**
 * print_string_with_escape - Prints a string with escape
 * for non-printable characters.
 * @str: The string to print.
 * @buffer: The character buffer.
 * @buffer_index: The index of the buffer.
 *
 * Return: The number of characters printed.
 */
int print_string_with_escape(char *str, char *buffer, int *buffer_index)
{
	int count = 0;

	while (*str)
	{
	if (*str >= 32 && *str < 127)
	{
		buffer[(*buffer_index)++] = *str;
		count++;
	}
	else
	{
		count += 4;
*buffer_index += _printf(buffer + *buffer_index, "\\x%02X",
				(unsigned char)(*str));
	}
	str++;
	}

	return (count);
}

/**
 * print_custom_conversion - Handles a custom conversion
 * specifier.
 * @specifier: The custom conversion specifier.
 * @args: The va_list of arguments.
 * @buffer: The character buffer.
 * @buffer_index: The index of the buffer.
 *
 * Return: The number of characters printed.
 */
int print_custom_conversion(char specifier, va_list args,
		char *buffer, int *buffer_index)
{
	switch (specifier)
	{
	case 'S':
	{
		char *str_arg = va_arg(args, char *);

	if (str_arg == NULL)
		str_arg = "(null)";
	return (print_string_with_escape(str_arg, buffer, buffer_index));
	}
	}

	return (0);
}

/**
 * _print_conversion - Handles a conversion specifier.
 * @specifier: The conversion specifier.
 * @args: The va_list of arguments.
 * @buffer: The character buffer.
 * @buffer_index: The index of the buffer.
 *
 * Return: The number of characters printed.
 */
int _print_conversions(char specifier, va_list args, char *buffer, int *buffer_index)
{
	if (specifier == 'S')
	{
	return (print_custom_conversion(specifier, args, buffer, buffer_index));
	}
}
