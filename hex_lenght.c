#include "main.h"

/**
 * length_of_hex - Calculate the number of digits in a
 * hexadecimal number.
 * @num: The hexadecimal number.
 *
 * Return: Number of digits in the hexadecimal representation.
 */
int length_of_hex(unsigned int num)
{
	int length = 0;

	do
	{
		num /= 16;
		length++;
	} while (num != 0);

	return (length);
}
