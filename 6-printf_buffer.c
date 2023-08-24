#include "main.h"

/**
 * print_pointer_address - Prints a pointer address in
 * hexadecimal.
 * @ptr: Pointer to print.
 * @buffer: Character buffer.
 * @buffer_index: Buffer index.
 *
 * Return: Number of characters printed.
 */
int print_pointer_address(void *ptr, char *buffer, int *buffer_index)
{
	return (*buffer_index += _printf(buffer + *buffer_index, "%p", ptr));
}

/**
 * _print_conversions - Handles a conversion specifier.
 * @specifier: The conversion specifier.
 * @args: The va_list of arguments.
 * @buffer: The character buffer.
 * @buffer_index: The index of the buffer.
 *
 * Return: The number of characters printed.
 */
int _print_conversions(char specifier, va_list args,
		char *buffer, int *buffer_index)
{
	if (specifier == 'S')
	{
	return (print_custom_conversion(specifier, args, buffer, buffer_index));
	}
	else if (specifier == 'p')
	{
		void *ptr_arg = va_arg(args, void *);

	return (print_pointer_address(ptr_arg, buffer, buffer_index));
	}

	return (0);
}
