#include "main.h"

/**
 * print_binary - prints a binary number
 * @args: the binary number to print
 * Return: number of bytes printed
*/

int print_binary(va_list args)
{
	int i, count = 0;
	unsigned int n = va_arg(args, unsigned int);
	int arr[32];

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	for (i = 0; n > 0; i++)
	{
		arr[i] = n % 2;
		n /= 2;
	}
	for (i -= 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
		count++;
	}
	return (count);
}
