#include "main.h"

/**
 * _printf - prints anything
 * @format: the format to print
 * 
 * Return: number of char printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		/*{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"R", print_rev},
		{"r", print_rot13},
		{"S", print_S},
		{"p", print_address},*/
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	
	va_start(args, format);
	i = print_md(format, specifiers, args);
	va_end(args);
	return (i);

}

/**
 * print_md - prints anything
 * @format: the format to print
 * @specifiers: the specifiers to print
 * @args: the arguments to print
 * 
 * Return: number of char printed
*/
int print_md(const char *format, specifier_t *specifiers, va_list args)
{
	char a;
	int count = 0, i = 0, j = 0;

	a = format[i];
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			i++;
			while (specifiers[j].type != NULL && a != *(specifiers[j].type) )
				j++;
			if (specifiers[j].type != NULL)
			{
				count += specifiers[j].f(args);
			}
			else
			{
				if (a == '\0')
					return (-1);
				if (a != '%')
					count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		
		i++;
		a = format[i];
	}
	return (count);
}
