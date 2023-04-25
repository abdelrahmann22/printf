#include "main.h"

/**
 * _printf - prints anything
 * @format: the format to print
 * Return: number of char printed
*/

int _printf(const char *format, ...)
{
	int count = -1, i;

	if (format != NULL)
	{
		va_list args;
		int (*f)(va_list);

		va_start(args, format);

		if (format[0] == '%' && format[1] == '\0')
			return (-1);

		count = 0;
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '%')
				{
					count += _putchar(format[i]);
					i++;
				}
				else if (format[i + 1] != '\0')
				{
					f = get_specifier(format[i + 1]);
					count += (f ? f(args) : _putchar(format[i]) + _putchar(format[i + 1]));
					i++;
				}
			}
			else
			{
				count += _putchar(format[i]);
			}
		}
		va_end(args);

	}
	return (count);
}
