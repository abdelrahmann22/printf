#include "main.h"

/**
 * print_char - prints a character
 * @args: the character to print
 * Return: number of char printed
*/

int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
