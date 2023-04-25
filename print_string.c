#include "main.h"

/**
 * print_string - prints a string
 * @args: the string to print
 * 
 * Return: number of char printed
*/

int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}
