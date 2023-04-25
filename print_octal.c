#include "main.h"

/**
 * print_octal - prints an octal number
 * @args: the octal number to print
 * Return: number of bytes printed
*/
int print_octal(va_list args)
{
	int i, counter = 0, arr[32];
	unsigned int n = va_arg(args, unsigned int);

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	for (i = 0; n > 0; i++)
	{
		arr[i] = n % 8;
		n /= 8;
	}
	for (i -= 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
		counter++;
	}
	return (counter);
}
