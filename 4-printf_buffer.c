#include "main.h"

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
	char buffer[1024]; /* Local buffer to accumulate characters */
	int buffer_index = 0; /* Index for the buffer */

	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
		format++;
		int num_chars = _print_conversions(*format, args, buffer, &buffer_index);
		count += num_chars;
	}
	else
	{
		buffer[buffer_index++] = *format;
	if (buffer_index == 1024)
	{
		count += write(1, buffer, buffer_index);
		buffer_index = 0;
	}
	}
	format++;
	}

	if (buffer_index > 0)
	{
		count += write(1, buffer, buffer_index);
	}

	va_end(args);

	return (count);
}
