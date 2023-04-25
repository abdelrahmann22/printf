#include "main.h"

/**
 * print_unsigned - prints an unsigned integer
 * @args: the unsigned integer to print
 * 
 * Return: number of char printed
*/
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0, x = 1;

	while ((n / x) > 9)
		x *= 10;
	while (x >= 1)
	{
		count += _putchar(((n / x) % 10) + '0');
		x /= 10;
	}
	return (count);
}
