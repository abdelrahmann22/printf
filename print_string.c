#include "main.h"

/**
 * print_string - prints a string
 * @args: the string to print
 * Return: number of char printed
*/

int print_string(va_list args)
{
	int i, count = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		count += _putchar(str[i]);

	return (count);
}
