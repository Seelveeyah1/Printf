#include "main.h"
#include "101-parse_helpers.c"
#include "101-print_helpers.c"
#include <stdarg.h>
/**
 * _prints_conversions - Handle conversion specifiers based
 * on format and specifier.
 * @format: Pointer to the format string.
 * @specifier: Current conversion specifier.
 * @args: va_list of arguments.
 * @buffer: Pointer to the output buffer.
 * @buffer_index: Pointer to the index of the buffer.
 *
 * Return: Number of characters printed.
 */
int _prints_conversions(const char *format, char specifier,
va_list args, char *buffer, int *buffer_index)
{
	char flags = parse_flags(&format);
	int field_width = parse_field_width(&format);
	int precision = parse_precision(&format);
	char length_modifier = parse_length_modifier(&format);

	char zero_pad = (flags & FLAG_ZERO) && !(flags & FLAG_MINUS) ? '0' : ' ';

	int chars_printed = 0;

    /* Handle custom specifiers */
	chars_printed = handle_custom_specifiers(specifier,
args, buffer, buffer_index, flags, length_modifier,
field_width, precision, zero_pad);

    /* Handle other specifiers...*/

	return (chars_printed);
}

/**
 * handle_custom_specifiers - Handle custom conversion
 * specifiers.
 * @specifier: Current conversion specifier.
 * @args: va_list of arguments.
 * @buffer: Pointer to the output buffer.
 * @buffer_index: Pointer to the index of the buffer.
 * @flags: Formatting flags.
 * @length_modifier: Length modifier.
 * @field_width: Field width.
 * @precision: Precision value.
 * @zero_pad: Character for zero padding.
 *
 * Return: Number of characters printed.
 */
static int handle_custom_specifiers(char specifier,
va_list args, char *buffer, int *buffer_index, char flags,
char length_modifier, int field_width, int precision, char zero_pad)
{
	int chars_printed = 0;

	if (specifier == 'S')
	{
	chars_printed = print_strings(args, buffer, buffer_index,
flags, length_modifier, field_width, precision);
	}
	else if (specifier == 'p')
	{
		void *ptr_arg = va_arg(args, void *);

		chars_printed = print_pointer_address(ptr_arg,
				buffer, buffer_index);
	}
    /* Add more custom specifier cases...*/

	return (chars_printed);
}

/* Add more functions for handling other specifiers...*/

