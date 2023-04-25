#include "main.h"

/**
 * print_binary - prints a binary number
 * @args: the binary number to print
 * 
 * Return: number of bytes printed
*/

int print_binary(va_list args)
{
	unsigned int i = 0, count = 0, binary, arr[32], num;
	
	num = va_arg(args, unsigned int);

	if (num < 1)
	{
		_putchar(48);
		count++;
		return (count);
	}
	else
	{
		while (num > 0)
		{
			binary = num % 2;
			num /= 2;
			arr[i] = binary;
			count++;
		}
		i = count - 1;
		while (i > 0)
		{
			_putchar(arr[i] + '0');
			i--;
		}
		_putchar(arr[i] + '0');
	}
	return (count);
}
