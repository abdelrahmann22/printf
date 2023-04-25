#include "main.h"

/**
 * print_binary - prints a binary number
 * @args: the binary number to print
 * Return: number of bytes printed
*/

int print_binary(va_list args)
{
	int count = 0, i;
	int *ptr;
	unsigned int a = va_arg(args, unsigned int);
	unsigned int t = a;

	while (t / 2 != 0)
	{
		t /= 2;
		count++;
	}
	count++;
	ptr = malloc(count * sizeof(int));
	if (ptr == NULL)
	{
		free(ptr);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		ptr[i] = a % 2;
		t /= 2;
	}
	for (i = count - 1; i >= 0; i--)
		_putchar(ptr[i] + '0');
	free(ptr);
	return (count);
}
