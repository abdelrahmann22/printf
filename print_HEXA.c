#include "main.h"

/**
 *	print_HEX - prints a number in hexadecimal
 *	@args: the number to print
 *	Return: number of bytes printed
*/
int print_HEX(va_list args)
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
		arr[i] = n % 16;
		n /= 16;
	}
	for (i -= 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			_putchar(arr[i] + 'A' - 10);
		else
			_putchar(arr[i] + '0');
		counter++;
	}
	return (counter);
}
